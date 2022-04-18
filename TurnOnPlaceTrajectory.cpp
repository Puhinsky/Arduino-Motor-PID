// 
// 
// 

#include "TurnOnPlaceTrajectory.h"
#include "Trajectory.h"
#include "Robot.h"


TurnOnPlaceTrajectory ;

TurnOnPlaceTrajectory::TurnOnPlaceTrajectory(Robot* robot, float relativeVelocity, float angle) {
	this->robot = robot;
	this->relativeVelocity = relativeVelocity;
	this->angle = angle;
}

void TurnOnPlaceTrajectory::run() {
	robot->turnOnPlace(relativeVelocity, angle);
}
