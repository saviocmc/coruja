#include <Arduino.h>

class LASER {

public:
	LASER(uint8_t pin, uint16_t threshold, void (* onLaserInterrupted)(void));
	void loop();
	bool getState();

private:
	uint8_t pin;
	uint16_t threshold;
	void (* callback)(void);
	bool state;
};
