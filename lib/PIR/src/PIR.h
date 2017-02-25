#include <Arduino.h>

/**
* An instance of this class is supposed to take care all PIR sensor connected on the board.
* You just need to call the PIR.loop() method inside the loop() function of the microcontroller.
*/
class PIR {

public:

	/*
	* @param interval Sets the minimum interval (in milliseconds) between two consecutive calls of the  callback functions.
	* This is to avoid calling the callback too many times, when the detected motion takes a long time to end.
	* Default is 1 second (100 milliseconds).
	*/
	PIR(unsigned long interval = 1000);

	/*
	* This method will read all sensors and call the callback function if a motion was detected.
	* Call it in the loop() function of the microcontroller.
	*/
	void loop();

	/*
	* Use this method to register the sensors connected on the board.
	* @param name The description of the sensor, for example: "Kitchen door", "Garage".
	* @param pin The number of the pin connected on the microcontroller.
	* @param callback A callback function to be called in case of a motion detection.
	*/
	void add(char* name, int pin, void (*callback)(char*, int));

private:
	unsigned long interval;
};
