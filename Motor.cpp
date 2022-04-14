// 
// 
// 

#include "Motor.h"

Motor::Motor(uint8_t pinA, uint8_t pinB, uint8_t signalPin) {
	this->pinA = pinA;
	this->pinB = pinB;
	this->signalPin = signalPin;
}

void Motor::setDirection(Direction direction)
{
	switch (direction)
	{
	case FORWARD:
		digitalWrite(pinA, false);
		digitalWrite(pinB, true);
		break;

	case BACKWARD:
		digitalWrite(pinA, true);
		digitalWrite(pinB, false);
		break;

	default:
		break;
	}
}

void Motor::setPWM(uint8_t pwm) {
	analogWrite(signalPin, pwm);
}


Motor ;

