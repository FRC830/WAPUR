#include <iostream>
#include <memory>
#include <string>
#include <Lib830.h>
#include <WPILib.h>
#include "input/GamepadF310.h"
#include "input/Toggle.h"

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "Arm.h"

class Robot: public frc::IterativeRobot {
public:
	static const int LEFT_FRONT_PWM = 5; //these numbers are subject to change
	static const int LEFT_BACK_PWM = 4;
	static const int RIGHT_FRONT_PWM = 3;
	static const int RIGHT_BACK_PWM = 1;

	static const int CLAMP_PCM = 0; //subject to change
	static const int RAISE_PCM = 1; //subject to change

	int TICKS_TO_ACCEL = 10;

	RobotDrive *drive;
	Lib830::GamepadF310 *pilot;
	Lib830::GamepadF310 *copilot;
	Arm *arm;

	Toggle clamp;

	void RobotInit() {
		chooser.AddDefault(autoNameDefault, autoNameDefault);
		chooser.AddObject(autoNameCustom, autoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &chooser);

		drive = new RobotDrive(
				new VictorSP(LEFT_FRONT_PWM),
				new VictorSP(LEFT_BACK_PWM),
				new VictorSP(RIGHT_FRONT_PWM),
				new VictorSP(RIGHT_BACK_PWM)
		);
		pilot = new Lib830::GamepadF310(0);
		copilot = new Lib830::GamepadF310(1);


		arm = new Arm(new Solenoid(CLAMP_PCM), new Solenoid(RAISE_PCM));
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

	bool up_was_pressed = false;
	bool up = false;
	void TeleopPeriodic() {
		//driving controls
		float cur_turn = pilot->LeftX();
		float cur_speed = pilot->RightY();

		float turn = Lib830::accel(prev_turn, cur_turn, TICKS_TO_ACCEL );
		float speed = Lib830::accel(prev_speed, cur_speed, TICKS_TO_ACCEL);

		drive->ArcadeDrive(speed, turn, false);

		prev_turn = turn;
		prev_speed = speed;

		//two ways to toggle
		bool up_is_pressed = copilot->ButtonState(Lib830::GamepadF310::BUTTON_A);
		if (up_is_pressed != up_was_pressed && up_is_pressed) {
			up = !up;
		}
		arm->setArm(up);

		up_was_pressed = up_is_pressed;

		//two ways to toggle
		bool getBall = clamp.toggle(copilot->ButtonState(Lib830::GamepadF310::BUTTON_B));
		arm->setClamp(getBall);

		SmartDashboard::PutBoolean("clamp open", clamp);

		arm->update();

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
