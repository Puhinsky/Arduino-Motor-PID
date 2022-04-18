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
	 void setMaxMin(float minValue, float maxValue);

	 float targetValue = 0;
	 float pK = 0;
	 float iK = 0;
	 float dK = 0;
	 float result = 0;

private:
	float iValue = 0;
	float previousError = 0;

	float minValue = 0;
	float maxValue = 0;
};

extern PID ;

#endif

