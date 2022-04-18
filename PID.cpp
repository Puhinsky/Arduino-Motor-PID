// 
// 
// 

#include "PID.h"

PID::PID()
{
}

PID::PID(float pK, float iK, float dK)
{
	this->pK = pK;
	this->iK = iK;
	this->dK = dK;
}

void PID::calculate(float currentValue, float dt) {
	float error = targetValue - currentValue;
	
	float pValue = error * pK;
	iValue += error * iK * dt;
	float dValue = dK * (error - previousError) / dt;
	previousError = error;

	result = constrain(pValue + iValue + dValue, minValue, maxValue);
}

void PID::setMaxMin(float minValue, float maxValue) {
	this->minValue = minValue;
	this->maxValue = maxValue;
}


PID ;

