// ForwardTrajectory.h

#ifndef _ForwardTrajectory_h
#define _ForwardTrajectory_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Trajectory.h"
#include "Robot.h"

class ForwardTrajectory : public Trajectory
{
public:
	ForwardTrajectory(Robot* robot, float relativeVelocity, float distance);
	void run();

	float relativeVelocity = 0;
	float distance = 0;
};

extern ForwardTrajectory ;

#endif