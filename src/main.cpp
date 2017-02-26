#include <Arduino.h>
#include <PIR.h>

PIR pir;

void onMotionDetected(char* identifier, int pin) {
	Serial.print("Moviment on: ");
	Serial.println(identifier);
}

void setup() {
	Serial.begin(9600);
	pir.add("Back door", 8, onMotionDetected);
	pir.add("Garage", 9, onMotionDetected);
}

void loop() {
	pir.loop();
}
