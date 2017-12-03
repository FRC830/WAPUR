/*
 * Arm.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: RatPack
 */
#include "Arm.h"

Arm::Arm(Solenoid *clamp, Solenoid *armRaise) {
	m_clamp = clamp;
	m_armRaise = armRaise;
	isUp = false;
	isClosed = false;
}

void Arm::update() {
	if (isUp) {
		m_armRaise->Set(1);
	}
	else {
		m_armRaise->Set(0);
	}

	if (isClosed) {
		m_clamp->Set(1);
	}
	else {
		m_clamp->Set(0);
	}
}

void Arm::setArm(bool toUP) {
	isUp = toUP;
}
void Arm::setClamp(bool toClose) {
	isClosed = toClose;
}
void Arm::reset() {
	isClosed = false;
	isUp = false;
}
bool Arm::getUp() {
	return isUp;
}
bool Arm::getClosed() {
	return isClosed;
}
Arm::~Arm() {}


