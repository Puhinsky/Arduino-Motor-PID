// PID.h

#ifndef _PID_h
#define _PID_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class PID
{
 public:
	 PID();
	 PID(float pK, float iK, float dK);

	 void calculate(float currentValue, float dt);

	 float targetValue;
	 float pK;
	 float iK;
	 float dK;
	 float result;

private:
	float iValue;
	float previousError;
};

extern PID ;

#endif

