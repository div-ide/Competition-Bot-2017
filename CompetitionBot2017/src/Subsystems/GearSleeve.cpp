#include "GearSleeve.h"
#include "../RobotMap.h"

GearSleeve::GearSleeve() : Subsystem("GearSleeve") {
	definedYet = false;
	isUp = false;
	isLoaded = false;
}

void GearSleeve::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void GearSleeve::Toggle() {
	if (!definedYet) {
		gearServo = new frc::Servo(4);
		loadedSwitch = new frc::DigitalInput(4);
		definedYet = true;
	}
	isUp = !isUp;
	if (isUp) {
		gearServo->Set(upPoint);
		isUpStatus = true;
	} else {
		gearServo->Set(downPoint);
		frc::Wait(0.8);
		gearServo->StopMotor();
		isUpStatus = false;
	}
	frc::SmartDashboard::PutBoolean("Gear Up?", isUpStatus);
}

void GearSleeve::Raise() {
	if (!definedYet) {
		gearServo = new frc::Servo(4);
		loadedSwitch = new frc::DigitalInput(4);
		definedYet = true;
	}
	isUp = true;
	gearServo->Set(upPoint);
	isUpStatus = true;
	frc::SmartDashboard::PutBoolean("Gear Up?", isUpStatus);
}

bool GearSleeve::CheckLoadedStatus() {
	if (!definedYet) {
		gearServo = new frc::Servo(GEAR_SERVO);
		loadedSwitch = new frc::DigitalInput(GEAR_STATUS_SWITCH);
		definedYet = true;
	}
	isLoaded = !loadedSwitch->Get();
	frc::SmartDashboard::PutBoolean("Gear Loaded?", isLoaded);
	if (isUp) {
		isUpStatus = !isUpStatus;
	}
	frc::SmartDashboard::PutBoolean("Gear Up?", isUpStatus);
	return isLoaded;
}
