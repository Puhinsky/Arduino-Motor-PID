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

PID leftPID = PID();
PID rightPID = PID();

void setup() {
	Serial.begin(9600);

	leftPID.targetValue = 5;
	leftPID.pK = 20;
	leftPID.iK = 10;

	rightPID.targetValue = 5;
	rightPID.pK = 20;
	rightPID.iK = 0;

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
	motor.setPWM(constrain(pid.result, 0, 255));
	encoder.reset();
}

void loop() {
}
