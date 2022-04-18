// TurnOnPlaceTrajectory.h

#ifndef _TurnOnPlaceTrajectory_h
#define _TurnOnPlaceTrajectory_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Trajectory.h"
#include "Robot.h"


class TurnOnPlaceTrajectory : public Trajectory
{
public:
	TurnOnPlaceTrajectory(Robot* robot, float relativeVelocity, float angle);
	void run();

	float relativeVelocity = 0;
	float angle = 0;
};

extern TurnOnPlaceTrajectory ;

#endif

