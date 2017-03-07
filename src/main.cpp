#include <Arduino.h>
#include <PIR.h>
#include <LASER.h>

LASER* laser;
PIR* pir;

void onPirMotionDetected(char* identifier, int pin) {
	static int count;
	Serial.print("Moviment on: ");
	Serial.print(identifier);
	Serial.print("\t");
	Serial.println(count++);
}

void onLaserMotionDetected() {
	static int count;
	Serial.print("Laser motion ");
	Serial.println(count++);
}

void setup() {
	Serial.begin(9600);
	laser = new LASER(A0, 800, onLaserMotionDetected);
	pir = new PIR(5000);
	pir->add("Back door", 8, onPirMotionDetected);
	pir->add("Garage", 9, onPirMotionDetected);
}

void loop() {
	pir->loop();
	laser->loop();
}
