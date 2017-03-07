#include <LASER.h>

LASER::LASER(uint8_t pin, uint16_t threshold, void (* callback)(void)) {
	this->pin = pin;
	this->threshold = threshold;
	this->callback = callback;
}

void LASER::loop() {
	bool newState = (analogRead(pin) > threshold);
	if (!newState && state)
		callback();
	state = newState;
}

bool LASER::getState() {
	return state;
}
