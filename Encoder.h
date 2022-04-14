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
	Encoder(uint8_t pin, void(*callback)());
	void onTick();
	void reset();
	unsigned int getCounter();

private:
	unsigned int counter = 0;

};

extern Encoder ;

#endif

