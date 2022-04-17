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

	 void Update(float updateRate);
	 void SetVelocity(float velocity);

private:
	Motor* motor;
	Encoder* encoder;
	PID* pid;
};

extern MotorRegulator ;

#endif

