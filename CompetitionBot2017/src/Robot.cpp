#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

#include <Commands/DriveWithJoystick.h>

#include "CommandBase.h"

class Robot: public frc::IterativeRobot {
public:
	static void VisionThread() {
		visionCam = CameraServer::GetInstance()->StartAutomaticCapture(0);
		CameraServer::GetInstance()->StartAutomaticCapture(1);
		visionCam.SetResolution(640, 480);
		cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo(visionCam.GetName());
		cs::CvSource outputStreamStd = CameraServer::GetInstance()->PutVideo("Test", 640, 480);
		cv::Mat source;
		cv::Mat output;
		while (true) {
			cvSink.GrabFrame(source);
			cv::cvtColor(source, output, cv::COLOR_BGR2GRAY);
			outputStreamStd.PutFrame(output);
		}

	}

	void RobotInit() override {
		std::thread visionThread(VisionThread);
		visionThread.detach();
	}

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override {

	}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void AutonomousInit() override {
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		driveWithJoystick = new DriveWithJoystick();
		driveWithJoystick->Start();
		pdp = new PowerDistributionPanel(0);
	}

	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();

		CommandBase::gearsleeve->CheckLoadedStatus();

		double volts = pdp->GetVoltage();
		double totalCurrent = pdp->GetTotalCurrent();
		//double current0 = pdp->GetCurrent(0);
		//double current1 = pdp->GetCurrent(1);
		//double current2 = pdp->GetCurrent(2);
		//double current3 = pdp->GetCurrent(3);
		//double current12 = pdp->GetCurrent(12);
		//double totalPower = volts*totalCurrent;

		SmartDashboard::PutNumber("Battery Voltage", volts);
		SmartDashboard::PutNumber("Total Current", totalCurrent);
		//SmartDashboard::PutNumber("TotalPower", totalPower);
		//SmartDashboard::PutNumber("Current 0", current0);
		//SmartDashboard::PutNumber("Current 1", current1);
		//SmartDashboard::PutNumber("Current 2", current2);
		//SmartDashboard::PutNumber("Current 3", current3);
		//SmartDashboard::PutNumber("Current 12", current12);
	}

	void TestPeriodic() override {
		frc::LiveWindow::GetInstance()->Run();
	}

private:
	cs::UsbCamera visionCam;
	Command* driveWithJoystick;
	PowerDistributionPanel* pdp;
	frc::SendableChooser<frc::Command*> chooser;
};

START_ROBOT_CLASS(Robot)
