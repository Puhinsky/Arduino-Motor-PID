// 
// 
// 

#include "Robot.h"
#include "MotorRegulator.h"\

#define pi 3.1415f

Robot::Robot(float wheelRadius, float axisLenght, float maxVelocity, MotorRegulator* leftMotorRegulator, MotorRegulator* rightMotorRegulator) {
	this->wheelRadius = wheelRadius;
	this->axisLenght = axisLenght;
	this->maxVelocity = maxVelocity;
	this->leftMotorRegulator = leftMotorRegulator;
	this->rightMotorRegulator = rightMotorRegulator;
}

void Robot::stop() {
	/*leftMotorRegulator->stop();
	rightMotorRegulator->stop();*/

	leftMotorRegulator->setVelocity(0);
	rightMotorRegulator->setVelocity(0);

	isMove = false;
	isWait = false;
}

void Robot::wait() {
	/*leftMotorRegulator->stop();
	rightMotorRegulator->stop();*/

	leftMotorRegulator->setVelocity(0);
	rightMotorRegulator->setVelocity(0);

	startTimer(waitTime);
	isMove = false;
	isWait = true;
}

void Robot::moveForward(float relativeVelocity, float distance) {
	float velocity = getAbsoluteVelocity(relativeVelocity);
	float radialVelocity = getRadialVelocity(velocity, wheelRadius);

	leftMotorRegulator->setVelocity(radialVelocity);
	rightMotorRegulator->setVelocity(radialVelocity);

	setDistance(distance);

	startTimer(distance * 1000 / velocity);
	isMove = true;
	isWait = false;
}

void Robot::turnOnPlace(float relativeVelocity, float angle) {
	float velocity = getAbsoluteVelocity(relativeVelocity);
	float radialVelocity = getRadialVelocity(velocity, wheelRadius);

	leftMotorRegulator->setVelocity(radialVelocity);
	rightMotorRegulator->setVelocity(-radialVelocity);

	setDistance(abs(pi * axisLenght * angle / 360.0f));

	startTimer(abs(pi * axisLenght * angle * 1000 / 360.0f / velocity));
	isMove = true;
	isWait = false;
}

void Robot::update(float updateRate) {
	if (getDistanceFromTicks(leftMotorRegulator->encoder->getAbsoluteCounter(), leftMotorRegulator->encoder->getStepsCount()) > targetDistance) {
		if (isMove)
			wait();
		else if (isWait)
			stop();
	}
	leftMotorRegulator->update(updateRate);
	rightMotorRegulator->update(updateRate);
}

bool Robot::isReady() {
	return !isMove && !isWait;
}

float Robot::getLinearVelocity(float radialVelocity, float radius) {
	return radialVelocity * radius;
}

float Robot::getRadialVelocity(float linearVelocity, float radius) {
	return linearVelocity / radius;
}

float Robot::getAbsoluteVelocity(float relativeVelocity) {
	return maxVelocity * relativeVelocity;
}

float Robot::getDistanceFromTicks(float ticks, float stepsCount) {
	return 2 * pi * wheelRadius * ticks / stepsCount;
}

void Robot::startTimer(unsigned long time) {
	startMoveTime = millis();
	timeToMove = time;
}

void Robot::setDistance(float distance) {
	targetDistance = distance;
	leftMotorRegulator->encoder->resetDistanceCounter();
}

Robot ;
