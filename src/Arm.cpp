/*
 * Arm.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: RatPack
 */
#include "Arm.h"

Arm::Arm(Solenoid *clamp_open, Solenoid *armLower) {
	m_clamp_open = clamp_open;
	m_armLower = armLower;
	isDown = false;
	isOpen = false;
}

void Arm::update() {
	if (isDown) {
		m_armLower->Set(1);
	}
	else {
		m_armLower->Set(0);
	}

	if (isOpen) {
		m_clamp_open->Set(1);
	}
	else {
		m_clamp_open->Set(0);
	}
}

void Arm::setArm(bool toDown) {
	isDown = toDown;
}
void Arm::setClamp(bool toOpen) {
	isOpen = toOpen;
}
void Arm::reset() {
	isOpen = false;
	isDown = false;
}
bool Arm::getDown() {
	return isDown;
}
bool Arm::getOpen() {
	return isOpen;
}
Arm::~Arm() {}


