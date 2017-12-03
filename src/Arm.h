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
	Arm(Solenoid *clamp, Solenoid *armRaise); //ask about line break sensor usage, would be useful

	void setArm(bool toUp);
	void setClamp(bool toClose);

	void update();
	void reset();

	bool getClosed();
	bool getUp();

	virtual ~Arm();
private:
	bool isClosed;
	bool isUp;
	Solenoid *m_clamp;
	Solenoid *m_armRaise;
};




#endif /* SRC_ARM_H_ */
