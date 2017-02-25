#include <Arduino.h>

// Put the pin number of all PIR sensors connected
// to the arduino on the array below
// It is used in the checkPir() function
const int PIR_PINS[] = {1,2,3,4};
int PIR_SIZE;

void setup(){
	Serial.begin(9600);
	PIR_SIZE = sizeof(PIR_PINS)/sizeof(PIR_PINS[0]);
}

bool checkPIR(){
	// TODO find a way more efficient to do this
	// Instead of the for, I could generate masks with the values in the array
	// and use the mask in the registers of arduino checking all PIR sensors at once
	for(int i = 0; i<PIR_SIZE; i++){
		if(digitalRead(PIR_PINS[i]))
			return true;
	}
	return false;
}

void loop(){
	if(checkPIR()){
		// Motion detected! Do something!
	}
}
