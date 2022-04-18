// 
// 
// 

#include "MotorRegulator.h"
#include "Motor.h"
#include "Encoder.h"
#include "PID.h"

#define pi 3.1415


MotorRegulator::MotorRegulator(Motor* motor, Encoder* encoder, PID* pid) {
	this->motor = motor;
	this->encoder = encoder;
	this->pid = pid;
}

void MotorRegulator::update(float updateRate) {
	float radialVelocity = calculateVelocity(encoder->getCounter(), encoder->getStepsCount(), updateRate);
	pid->calculate(radialVelocity, updateRate);
	motor->setDeltaPwm(pid->result);
	encoder->reset();
}

void MotorRegulator::setVelocity(float velocity) {
	if (velocity >= 0) {
		motor->setDirection(FORWARD);
	}
	else {
		motor->setDirection(BACKWARD);
	}

	pid->targetValue = abs(velocity);
}

void MotorRegulator::stop() {
	pid->targetValue = 0;
	motor->setDirection(STOP);
}

float MotorRegulator::calculateVelocity(uint8_t ticks, uint8_t stepsCount, float time) {
	return 2 * pi * float(ticks) / (float(stepsCount) * time);
}

MotorRegulator;