#include "MotorRegulator.h"
#include "Encoder.h"
#include "Motor.h"
#include "PID.h"
#include "Robot.h"
#include "TimerOne.h"
#include "Trajectory.h"
#include "ForwardTrajectory.h"
#include "TurnOnPlaceTrajectory.h"

void onLeftEncoder();
void onRightEncoder();

#define PIDUpdateRate 0.05

Encoder* leftEncoder = new Encoder(3, onLeftEncoder, 40);
Encoder* rightEncoder = new Encoder(2, onRightEncoder, 40);

Motor* leftMotor = new Motor(12, 4, 5);
Motor* rightMotor = new Motor(10, 8, 13);

PID* leftPID = new PID(3, 3, 0.01); // 8 4 0.01
PID* rightPID = new PID(3, 3, 0.01);

MotorRegulator* leftMotorRegulator = new MotorRegulator(leftMotor, leftEncoder, leftPID);
MotorRegulator* rightMotorRegulator = new MotorRegulator(rightMotor, rightEncoder, rightPID);

Robot* robot = new Robot(0.033f, 0.125f, 0.5f, leftMotorRegulator, rightMotorRegulator);

Trajectory* path[8];
uint8_t trajectoryCounter = 0;

void setup() {
	leftPID->setMaxMin(-255, 255);
	rightPID->setMaxMin(-255, 255);

	Serial.begin(9600);

	//path[0] = new ForwardTrajectory(robot, 0.4f, 0.5f);
	//path[1] = new TurnOnPlaceTrajectory(robot, 0.2f, 135.0f);
	//path[2] = new TurnOnPlaceTrajectory(robot, -0.2f, 60.0f);

	//path[3] = new ForwardTrajectory(robot, 0.4f, 0.5f);
	//path[4] = new TurnOnPlaceTrajectory(robot, 0.2f, 135.0f);
	//path[5] = new TurnOnPlaceTrajectory(robot, -0.2f, 60.0f);

	//path[6] = new ForwardTrajectory(robot, 0.4f, 0.5f);
	//path[7] = new TurnOnPlaceTrajectory(robot, 0.2f, 135.0f);
	//path[8] = new TurnOnPlaceTrajectory(robot, -0.2f, 60.0f);

	//path[9] = new ForwardTrajectory(robot, 0.4f, 0.5f);
	//path[10] = new TurnOnPlaceTrajectory(robot, 0.2f, 135.0f);
	//path[11] = new TurnOnPlaceTrajectory(robot, -0.2f, 60.0f);

	path[0] = new ForwardTrajectory(robot, 0.4f, 0.5f);
	path[1] = new TurnOnPlaceTrajectory(robot, 0.2f, 60.0f);

	path[2] = new ForwardTrajectory(robot, 0.4f, 0.5f);
	path[3] = new TurnOnPlaceTrajectory(robot, 0.2f, 60.0f);

	path[4] = new ForwardTrajectory(robot, 0.4f, 0.5f);
	path[5] = new TurnOnPlaceTrajectory(robot, 0.2f, 60.0f);

	path[6] = new ForwardTrajectory(robot, 0.4f, 0.5f);
	path[7] = new TurnOnPlaceTrajectory(robot, 0.2f, 60.0f);

	Timer1.initialize(PIDUpdateRate * 1000000);
	Timer1.attachInterrupt(onTimer);
}

void onLeftEncoder() {
	leftEncoder->onTick();
}

void onRightEncoder() {
	rightEncoder->onTick();
}

void onTimer() {
	robot->update(PIDUpdateRate);
}

void loop() {

	if (robot->isReady() == true && trajectoryCounter < 8) {
		path[trajectoryCounter]->run();
		trajectoryCounter++;
	}
}

void debugGraph(float graph1, float graph2) {
	Serial.print(graph1);
	Serial.print(",");
	Serial.println(graph2);
}