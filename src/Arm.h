/*
 * Arm.h
 *
 *  Created on: Nov 19, 2017
 *      Author: RatPack
 */

#ifndef SRC_ARM_H_
#define SRC_ARM_H_

#include "Lib830.h"
#include "WPILib.h"
class Arm {
public:
	Arm(Solenoid *clamp_open, Solenoid *armLower); //ask about line break sensor usage, would be useful

	void setArm(bool toDown);
	void setClamp(bool toOpen);

	void update();
	void reset();

	bool getOpen();
	bool getDown();

	virtual ~Arm();
private:
	bool isOpen;
	bool isDown;
	Solenoid *m_clamp_open;
	Solenoid *m_armLower;
};




#endif /* SRC_ARM_H_ */
