#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	definedYet = false;
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void DriveTrain::Drive(double acceleration, double steering) {
	if (!definedYet) {
		driveBase = new frc::RobotDrive(0, 1, 2, 3);
		leftEncoder = new frc::Encoder(0, 1);
		rightEncoder = new frc::Encoder(2, 3);
		gyro = new frc::ADXRS450_Gyro();
		leftEncoder->SetDistancePerPulse(6*3.14159);
		rightEncoder->SetDistancePerPulse(6*3.14159);
		leftEncoder->SetReverseDirection(true);
		leftEncoder->SetSamplesToAverage(7);
		rightEncoder->SetSamplesToAverage(7);
		definedYet = true;
	}
	driveBase->ArcadeDrive(acceleration, steering);
	frc::SmartDashboard::PutNumber("leftEncoder", ((double)leftEncoder->GetRaw()/1440)*6*3.14159);
	frc::SmartDashboard::PutNumber("rightEncoder", ((double)rightEncoder->GetRaw()/1440)*6*3.14159);
	double speed = (((double)leftEncoder->GetRaw()/1440)*6*3.14159+((double)rightEncoder->GetRaw()/1440)*6*3.14159)/2;
	double speedKph = speed*3600*254/100000;
	frc::SmartDashboard::PutNumber("speed", speed);
	frc::SmartDashboard::PutNumber("speedKph", speedKph);
	frc::SmartDashboard::PutNumber("gyroRadians", (gyro->GetAngle()/360)*2*3.14159);
}