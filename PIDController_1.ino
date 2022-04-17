#include "MotorRegulator.h"
#include "Encoder.h"
#include "Motor.h"
#include "PID.h"
#include "TimerOne.h"

void onLeftEncoder();
void onRightEncoder();

#define PIDUpdateRate 0.05

Encoder* leftEncoder = new Encoder(3, onLeftEncoder);
Encoder* rightEncoder = new Encoder(2, onRightEncoder);

Motor* leftMotor = new Motor(12, 4, 5);
Motor* rightMotor = new Motor(10, 8, 13);

PID* leftPID = new PID(8, 4, 0.01);
PID* rightPID = new PID(8, 4, 0.01);

MotorRegulator leftMotorRegulator = MotorRegulator(leftMotor, leftEncoder, leftPID);
MotorRegulator rightMotorRegulator = MotorRegulator(rightMotor, rightEncoder, rightPID);

void setup() {
	Serial.begin(9600);

	leftMotorRegulator.SetVelocity(2);
	rightMotorRegulator.SetVelocity(-2);

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
	leftMotorRegulator.Update(PIDUpdateRate);
	rightMotorRegulator.Update(PIDUpdateRate);
}

void loop() {
}

void debugGraph(float graph1, float graph2) {
	Serial.print(graph1);
	Serial.print(",");
	Serial.println(graph2);
}