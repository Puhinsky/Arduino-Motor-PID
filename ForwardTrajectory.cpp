// 
// 
// 

#include "ForwardTrajectory.h"
#include "Trajectory.h"
#include "Robot.h"

ForwardTrajectory::ForwardTrajectory(Robot* robot, float relativeVelocity, float distance) {
	this->robot = robot;
	this->relativeVelocity = relativeVelocity;
	this->distance = distance;
}

void ForwardTrajectory::run() {
	robot->moveForward(relativeVelocity, distance);
}

ForwardTrajectory;