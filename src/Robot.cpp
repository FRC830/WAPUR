#include <iostream>
#include <memory>
#include <string>
#include <Lib830.h>
#include <WPILib.h>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

class Robot: public frc::IterativeRobot {
public:
	static const int LEFT_FRONT_PWM = 0; //these numbers are subject to change
	static const int LEFT_BACK_PWM = 1;
	static const int RIGHT_FRONT_PWM = 9;// 2;
	static const int RIGHT_BACK_PWM = 8; //3;

	//declare a drive train object & a Lib830:: gamepad object 
	//object declaration example: Motor *motor
	RobotDrive *drive;
	Lib830:: GamepadF310 *gamepad;
	void RobotInit() {
		chooser.AddDefault(autoNameDefault, autoNameDefault);
		chooser.AddObject(autoNameCustom, autoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &chooser);

		/*initialize drive train (look at http://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1RobotDrive.html
		for constructor */
		//ex: motor = new Motor (new VictorSP(MOTOR_PWM));
		drive = new RobotDrive (new VictorSP(LEFT_FRONT_PWM), new VictorSP(LEFT_BACK_PWM), new VictorSP(RIGHT_FRONT_PWM), new VictorSP(RIGHT_BACK_PWM));

		//initalize game pad, constructor is Lib830::Gamepad(0)
		gamepad = new Lib830::GamepadF310(0);
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
		autoSelected = chooser.GetSelected();
		// std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		if (autoSelected == autoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void AutonomousPeriodic() {
		if (autoSelected == autoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}
	void TeleopInit() {

	}
	float prev_speed = 0;
	float prev_turn = 0;

	void TeleopPeriodic() {
		
		float turn = gamepad->RightX(); /*from gamepad class, LeftX(),LeftY(),RightX(),RightY() correspond to game pad controlls
		call function with gamepadobject -> Function() */
			
		float speed = gamepad->LeftY(); /*different axis than speed!*/
 		drive->ArcadeDrive(speed,turn);


		//accel function after basic drive train works 

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
