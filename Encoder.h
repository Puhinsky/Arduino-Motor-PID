// Encoder.h

#ifndef _Encoder_h
#define _Encoder_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Encoder
{
public:
	Encoder(uint8_t pin, void(*callback)(), uint8_t stepsCount);
	void onTick();
	void reset();
	void resetDistanceCounter();
	uint8_t getCounter();
	uint8_t getStepsCount();
	unsigned long getAbsoluteCounter();

private:
	uint8_t counter = 0;
	uint8_t stepsCount = 1;
	unsigned long distanceCounter;
};

extern Encoder ;

#endif

