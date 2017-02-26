#include "PIR.h"

// Represents one PIR sensor (node) in the list of sensors.
struct sensor {
	char* name;
	int pin;
	void (*callback)(char*, int);
	unsigned long lastCallbackCall;
	sensor* next;
};

// The head of the linked list of sensors.
sensor* head;

// Constructor.
PIR::PIR(unsigned long interval) {
	this-> interval = interval;
	head = NULL;
}

// Pass through all sensor in the list and checks if a movement was detected.
// If was, it calls the callback function if the time since the last call is greater than the interval.
// It does this second test to avoid calling the callback too many times in a short period of time.
void PIR::loop() {
	sensor* cursor = head;
	while (cursor!=NULL) {
		if(digitalRead(cursor->pin) && (millis() - cursor->lastCallbackCall) > interval){
			cursor->lastCallbackCall = millis();
			cursor->callback(cursor->name, cursor->pin);
		}
		cursor = cursor->next;
	}
}

// Add a new sensor in the linked list.
// In the end, the new sensor will be the head of the list.
void PIR::add(char *name, int pin, void (*callback)(char* , int)) {
	pinMode(pin, INPUT);
	sensor* new_sensor = (sensor*) malloc(sizeof(sensor));
	new_sensor->name = name;
	new_sensor->pin = pin;
	new_sensor->callback = callback;
	new_sensor->next = head;
	head = new_sensor;
}
