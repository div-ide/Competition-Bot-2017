#include "GearSleeve.h"
#include "../RobotMap.h"

GearSleeve::GearSleeve() : Subsystem("GearSleeve") {
}

void GearSleeve::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void GearSleeve::Toggle() {
	if (!definedYet) {
		//gearServo = new frc::Servo(GEAR_SERVO);
		loadedSwitch = new frc::DigitalInput(GEAR_STATUS_SWITCH);
		upLimit = new frc::DigitalInput(GEAR_LIMIT_SWITCH_UP);
		definedYet = true;
	}
	isUp = !isUp;
	if (isUp) {
		//gearServo->Set(upPoint);
		/*gearMotor->Set(upPower);
		while (upLimit->Get()) {}
		gearMotor->Set(0.0);*/
		isUpStatus = true;
	} else {
		//gearServo->Set(downPoint);
		//frc::Wait(0.8);
		//gearServo->StopMotor();
		/*gearMotor->Set(downPower);
		while (downLimit->Get()) {}
		gearMotor->Set(0.0);*/
		isUpStatus = false;
	}
	frc::SmartDashboard::PutBoolean("Gear Up?", isUpStatus);
}

void GearSleeve::Raise() {
	if (!definedYet) {
		//gearServo = new frc::Servo(GEAR_SERVO);
		loadedSwitch = new frc::DigitalInput(GEAR_STATUS_SWITCH);
		/*gearMotor = new frc::VictorSP(GEAR_MOTOR);
		upLimit = new frc::DigitalInput(GEAR_LIMIT_SWITCH_UP);
		downLimit = new frc::DigitalInput(GEAR_LIMIT_SWITCH_DOWN);*/
		definedYet = true;
	}
	isUp = true;
	//gearServo->Set(upPoint);
	isUpStatus = true;
	/*gearMotor->Set(upPower);
	while (upLimit->Get()) {}
	gearMotor->Set(0.0);*/
	frc::SmartDashboard::PutBoolean("Gear Up?", isUpStatus);
}

bool GearSleeve::CheckLoadedStatus() {
	if (!definedYet) {
		//gearServo = new frc::Servo(GEAR_SERVO);
		loadedSwitch = new frc::DigitalInput(GEAR_STATUS_SWITCH);
		/*gearMotor = new frc::VictorSP(GEAR_MOTOR);
		upLimit = new frc::DigitalInput(GEAR_LIMIT_SWITCH_UP);
		downLimit = new frc::DigitalInput(GEAR_LIMIT_SWITCH_DOWN);*/
		definedYet = true;
	}
	isLoaded = !loadedSwitch->Get();
	frc::SmartDashboard::PutBoolean("Gear Loaded?", isLoaded);
	if (isUp) {
		isUpStatus = !isUpStatus;
	}
	frc::SmartDashboard::PutBoolean("Gear Up?", isUpStatus);
	/*frc::SmartDashboard::PutBoolean("Upper Limit", upLimit);
	frc::SmartDashboard::PutBoolean("Lower Limit", downLimit);*/
	return isLoaded;
}

void GearSleeve::Reset() {
	//gearServo->Set(downPoint);
	isUp = false;
	isUpStatus = false;
	isLoaded = false;
	frc::SmartDashboard::PutBoolean("Gear Loaded?", isLoaded);
	frc::SmartDashboard::PutBoolean("Gear Up?", isUpStatus);
}
