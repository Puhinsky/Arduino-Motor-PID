// Trajectory.h

#ifndef _Trajectory_h
#define _Trajectory_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Robot.h"

class Trajectory
{
 public:
	 void virtual run();

protected:
	Robot* robot;
};

extern Trajectory ;

#endif

