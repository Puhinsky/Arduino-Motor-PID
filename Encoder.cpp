// 
// 
// 

#include "Encoder.h"


Encoder::Encoder(uint8_t pin, void(*callback)()) {
	pinMode(pin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(pin), callback, CHANGE);
}

void Encoder::onTick() {
	counter++;
}

void Encoder::reset() {
	counter = 0;
}

uint8_t Encoder::getCounter() {
	return counter;
}

Encoder ;