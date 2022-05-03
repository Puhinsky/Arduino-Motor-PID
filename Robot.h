// Robot.h

#ifndef _Robot_h
#define _Robot_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "MotorRegulator.h"

class Robot
{

public:
	Robot(float wheelRadius, float axisLenght, float maxVelocity, MotorRegulator* leftMotorRegulator, MotorRegulator* rightMotorRegulator);

	void stop();
	void wait();
	void moveForward(float velocity, float distance);
	void turnOnPlace(float relativeVelocity, float angle);
	void update(float updateRate);

	bool isMove = false;
	bool isWait = false;
	bool isReady();

private:
	float wheelRadius = 0.0f;
	float axisLenght = 0.0f;
	float maxVelocity = 0.0f;

	float targetDistance = 0.0f;

	unsigned long startMoveTime = 0;
	unsigned long timeToMove = 0;
	unsigned long waitTime = 500;

	MotorRegulator* leftMotorRegulator;
	MotorRegulator* rightMotorRegulator;

	float getLinearVelocity(float radialVelocity, float radius);
	float getRadialVelocity(float linearVelocity, float radius);
	float getAbsoluteVelocity(float relativeVelocity);
	float getDistanceFromTicks(float ticks, float stepsCount);

	void startTimer(unsigned long time);
	void setDistance(float distance);
};

extern Robot ;

#endif

