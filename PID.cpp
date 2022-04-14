// 
// 
// 

#include "PID.h"

void PID::calculate(float currentValue, float dt) {
	float error = targetValue - currentValue;
	
	float pValue = error * pK;
	iValue += error * iK * dt;

	result = pValue + iValue;
}


PID ;

