#include <Arduino.h>

/* PERFORMANCE BRANCH */

/* For each PIR sensor connected to the microcontroller, put the number of the pin
connected in the array PIR_PINS and the respective identifier name in the array PIR_NAMES */
const int PIR_PINS[] = 		{8,9};
const char* PIR_NAMES[] = 	{"Back door","Garage"};
const int PIR_SIZE = sizeof(PIR_PINS)/sizeof(PIR_PINS[0]);
int lastCall[PIR_SIZE];

/* Sets the minimum interval (in milliseconds) between two consecutive calls of the  callback functions.
* This is to avoid calling the callback too many times, when the detected motion takes a long time to end. */
const unsigned long interval = 2000;

void setup(){
	Serial.begin(9600);
}

void loop(){

	/* To maybe Do: there is a more efficient way to do the checking
	* Instead of the for, I could generate masks with the values in the array
	* and use the mask in the registers of arduino checking all PIR sensors at once */

	for(int i = 0; i<PIR_SIZE; i++) {
		if(digitalRead(PIR_PINS[i]) && (millis() - lastCall[i] > interval)){

			/** ON MOTION DETECTED **/
			Serial.print("Moviment on: ");
			Serial.println(PIR_NAMES[i]);
			/** -------------------- **/

			lastCall[i] = millis();
		}
	}
}
