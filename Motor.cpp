// 
// 
// 

#include "Motor.h"

Motor::Motor(uint8_t pinA, uint8_t pinB, uint8_t signalPin) {
	this->pinA = pinA;
	this->pinB = pinB;
	this->signalPin = signalPin;
}

void Motor::setDirection(Direction direction) {
	switch (direction) {
	case FORWARD:
		digitalWrite(pinA, false);
		digitalWrite(pinB, true);
		break;

	case BACKWARD:
		digitalWrite(pinA, true);
		digitalWrite(pinB, false);
		break;

	case STOP:
		digitalWrite(pinA, true);
		digitalWrite(pinB, true);

	default:
		break;
	}
}

void Motor::setPwm(uint8_t pwm) {
	analogWrite(signalPin, pwm);
}

void Motor::setDeltaPwm(int8_t deltaPwm) {
	if (deltaPwm >= 0) {
		currentPwm = constrain(currentPwm, 0, 255 - deltaPwm);
	}
	else {
		currentPwm = constrain(currentPwm, -deltaPwm, 255);
	}
	currentPwm = uint8_t(currentPwm + deltaPwm);
	setPwm(currentPwm);
}


Motor;