#include <iostream>
#include <memory>
#include <string>
#include <Lib830.h>
#include <WPILib.h>
#include <input/Toggle.h>
#include <input/GamepadF310.h>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

//button a is 0
//button b is 1
//button x is 2
//button y is 3
//D-pad up is 4
//D-pad down is 5

class Robot: public frc::IterativeRobot {
public:

	static const int DIO_0 = 0;
	static const int DIO_1 = 1;
	static const int DIO_2 = 2;
	static const int DIO_3 = 3;
	static const int DIO_4 = 4;
	static const int DIO_5 = 5;

	static const int PWM_0 = 0;
	static const int PWM_1 = 1;
	static const int PWM_2 = 2;
	static const int PWM_3 = 3;
	static const int PWM_4 = 4;
	static const int PWM_5 = 5;
	//declare a drive train object & a Lib830:: gamepad object 
	//object declaration example: Motor *motor

	DigitalInput *DIO0;
	DigitalInput *DIO1;
	DigitalInput *DIO2;
	DigitalInput *DIO3;
	DigitalInput *DIO4;
	DigitalInput *DIO5;

	VictorSP *pwm0;
	VictorSP *pwm1;
	VictorSP *pwm2;
	VictorSP *pwm3;
	VictorSP *pwm4;
	VictorSP *pwm5;


	Lib830::GamepadF310 *pilot;
	RobotDrive *drivetrain;


	void RobotInit() {


		/*initialize drive train (look at http://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1RobotDrive.html
		for constructor */
		//ex: motor = new Motor (new VictorSP(MOTOR_PWM));

		DIO0 = new DigitalInput(DIO_0);
		DIO1 = new DigitalInput(DIO_1);
		DIO2 = new DigitalInput(DIO_2);
		DIO3 = new DigitalInput(DIO_3);
		DIO4 = new DigitalInput(DIO_4);
		DIO5 = new DigitalInput(DIO_5);

		pwm0 = new VictorSP(PWM_0);
		pwm1 = new VictorSP(PWM_1);
		pwm2 = new VictorSP(PWM_2);
		pwm3 = new VictorSP(PWM_3);
		pwm4 = new VictorSP(PWM_4);
		pwm5 = new VictorSP(PWM_5);

		//initalize game pad, constructor is Lib830::Gamepad(0)
		pilot = new Lib830::GamepadF310(0);
	}

	/*
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit() override {

	}

	void AutonomousPeriodic() {

	}
	void TeleopInit() {

	}


	void TeleopPeriodic() {


		if (DIO0->Get() == true) {
			pwm0->Set(1);
		}
		else {
			pwm0->Set(0);
		}

		if (DIO1->Get() == true) {
			pwm1->Set(1);
			SmartDashboard::PutBoolean("pwm1 speed",pwm1->Get());
		}
		else {
			pwm1->Set(0);
		}

		if (DIO2->Get() == true) {
			pwm2->Set(1);
		}
		else {
			pwm2->Set(0);
		}

		if (DIO3->Get() == true) {
			pwm3->Set(1);
		}
		else {
			pwm3->Set(0);
		}

		if (DIO4->Get() == true) {
			pwm4->Set(1);
		}
		else {
			pwm4->Set(0);
		}

		if (DIO5->Get() == true) {
			pwm5->Set(1);
		}
		else {
			pwm5->Set(0);
		}


		SmartDashboard::PutNumber("pwm 0", pwm0->Get());
		SmartDashboard::PutBoolean("digital input", DIO0->Get());


	}

	void TestPeriodic() {
	}

private:

};

START_ROBOT_CLASS(Robot)
