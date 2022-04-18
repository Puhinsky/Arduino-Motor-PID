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
	leftMotorRegulator->stop();
	rightMotorRegulator->stop();
	isMove = false;
	isWait = false;
}

void Robot::wait() {
	leftMotorRegulator->stop();
	rightMotorRegulator->stop();
	startTimer(waitTime);
	isMove = false;
	isWait = true;
}

void Robot::moveForward(float relativeVelocity, float distance) {
	float velocity = getAbsoluteVelocity(relativeVelocity);
	float radialVelocity = getRadialVelocity(velocity, wheelRadius);

	leftMotorRegulator->setVelocity(radialVelocity);
	rightMotorRegulator->setVelocity(radialVelocity);

	startTimer(distance * 1000 / velocity);
	isMove = true;
	isWait = false;
}

void Robot::turnOnPlace(float relativeVelocity, float angle) {
	//angle *= 1.1f;
	float velocity = getAbsoluteVelocity(relativeVelocity);
	float radialVelocity = getRadialVelocity(velocity, wheelRadius);

	leftMotorRegulator->setVelocity(radialVelocity);
	rightMotorRegulator->setVelocity(-radialVelocity);

	startTimer(abs(pi * axisLenght * angle * 1000 / 360.0f / velocity));
	isMove = true;
	isWait = false;
}

void Robot::update(float updateRate) {
	if (millis() - startMoveTime > timeToMove) {
		if (isMove)
			wait();
		else if (isWait)
			stop();
	}

	Serial.println(timeToMove);
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

void Robot::startTimer(unsigned long time) {
	startMoveTime = millis();
	timeToMove = time;
}

Robot ;
