// 
// 
// 

#include "MotorRegulator.h"
#include "Motor.h"
#include "Encoder.h"
#include "PID.h"


MotorRegulator::MotorRegulator(Motor* motor, Encoder* encoder, PID* pid) {
	this->motor = motor;
	this->encoder = encoder;
	this->pid = pid;
}

void MotorRegulator::Update(float updateRate)
{
	pid->calculate(encoder->getCounter(), updateRate);
	motor->setDeltaPwm(pid->result);
	encoder->reset();
}

void MotorRegulator::SetVelocity(float velocity)
{
	if (velocity >= 0) {
		motor->setDirection(FORWARD);
	}
	else {
		motor->setDirection(BACKWARD);
	}

	pid->targetValue = abs(velocity);
}

MotorRegulator;
