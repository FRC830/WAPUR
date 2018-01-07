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
	//declare a drive train object & a Lib830:: gamepad object 
	//object declaration example: Motor *motor

	DigitalOutput *DIO0;
	DigitalOutput *DIO1;
	DigitalOutput *DIO2;
	DigitalOutput *DIO3;
	DigitalOutput *DIO4;
	DigitalOutput *DIO5;


	Lib830::GamepadF310 *pilot;
	RobotDrive *drivetrain;


	void RobotInit() {
		chooser.AddDefault(autoNameDefault, autoNameDefault);
		chooser.AddObject(autoNameCustom, autoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &chooser);

		/*initialize drive train (look at http://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1RobotDrive.html
		for constructor */
		//ex: motor = new Motor (new VictorSP(MOTOR_PWM));

		DIO0 = new DigitalOutput(DIO_0);
		DIO1 = new DigitalOutput(DIO_1);
		DIO2 = new DigitalOutput(DIO_2);
		DIO3 = new DigitalOutput(DIO_3);
		DIO4 = new DigitalOutput(DIO_4);
		DIO5 = new DigitalOutput(DIO_5);


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
	Toggle dio_0;
	Toggle dio_1;
	Toggle dio_2;
	Toggle dio_3;
	Toggle dio_4;
	Toggle dio_5;


	void TeleopPeriodic() {

		DIO0->Set(dio_0.toggle(pilot->ButtonState(Lib830::GamepadF310::BUTTON_A)));
		DIO1->Set(dio_1.toggle(pilot->ButtonState(Lib830::GamepadF310::BUTTON_B)));
		DIO2->Set(dio_2.toggle(pilot->ButtonState(Lib830::GamepadF310::BUTTON_X)));
		DIO3->Set(dio_3.toggle(pilot->ButtonState(Lib830::GamepadF310::BUTTON_Y)));
		DIO4->Set(dio_4.toggle(pilot->DPadUp()));
		DIO5->Set(dio_5.toggle(pilot->DPadDown()));


	}

	void TestPeriodic() {
		lw->Run();
	}

private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;
};

START_ROBOT_CLASS(Robot)
