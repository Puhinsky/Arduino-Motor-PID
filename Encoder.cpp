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

unsigned int Encoder::getCounter() {
	return counter;
}

Encoder ;