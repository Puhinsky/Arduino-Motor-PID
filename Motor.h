// Motor.h

#ifndef _Motor_h
#define _Motor_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum Direction
{
	FORWARD,
	BACKWARD
};

class Motor
{
 public:
	 Motor(uint8_t pinA, uint8_t pinB, uint8_t signalPin);
	 void setDirection(Direction direction);
	 void setPWM(uint8_t pwm);

private:
	uint8_t pinA;
	uint8_t pinB;
	uint8_t signalPin;
};

extern Motor ;

#endif

