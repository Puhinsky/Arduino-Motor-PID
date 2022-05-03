// MotorRegulator.h

#ifndef _MotorRegulator_h
#define _MotorRegulator_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Motor.h"
#include "Encoder.h"
#include "PID.h"

class MotorRegulator
{
 public:
	 MotorRegulator(Motor* motor, Encoder* encoder, PID* pid);

	 void update(float updateRate);
	 void setVelocity(float velocity);
	 void stop();

	 Encoder* encoder;

private:
	Motor* motor;
	PID* pid;

	float calculateVelocity(uint8_t ticks, uint8_t stepsCount, float time);
};

extern MotorRegulator ;

#endif

