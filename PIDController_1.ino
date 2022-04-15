#include "Encoder.h"
#include "Motor.h"
#include "PID.h"
#include "TimerOne.h"

void onLeftEncoder();
void onRightEncoder();

#define PIDUpdateRate 0.05

Encoder leftEncoder = Encoder(3, onLeftEncoder);
Encoder rightEncoder = Encoder(2, onRightEncoder);

Motor leftMotor = Motor(12, 4, 5);
Motor rightMotor = Motor(10, 8, 13);

PID leftPID = PID(8, 4, 0.01);
PID rightPID = PID(3, 4, 0.01);

void setup() {
	Serial.begin(9600);

	leftPID.targetValue = 4;

	rightPID.targetValue = 4;

	Timer1.initialize(PIDUpdateRate * 1000000);
	Timer1.attachInterrupt(onTimer);

	leftMotor.setDirection(FORWARD);
	rightMotor.setDirection(FORWARD);
}

void onLeftEncoder() {
	leftEncoder.onTick();
}

void onRightEncoder() {
	rightEncoder.onTick();
}


void onTimer() {
	MotorControl(leftMotor, leftEncoder, leftPID, PIDUpdateRate);
	MotorControl(rightMotor, rightEncoder, rightPID, PIDUpdateRate);
}

void MotorControl(Motor& motor, Encoder& encoder, PID& pid, float updateRate) {
	pid.calculate(encoder.getCounter(), updateRate);
	motor.setDeltaPwm(pid.result);
	//debugGraph(pid.result, encoder.getCounter());
	encoder.reset();
}

void loop() {
}

void debugGraph(float graph1, float graph2) {
	Serial.print(graph1);
	Serial.print(",");
	Serial.println(graph2);
}