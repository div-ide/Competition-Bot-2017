#include "Winch.h"
#include "../RobotMap.h"

Winch::Winch() : Subsystem("Winch") {
}

void Winch::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new ClimbRope());
}


// power is motor speed
void Winch::SetMotorPower(double power) {
	// if not defined, define variables
	if (!definedYet) {
		winchMotor = new frc::VictorSP(WINCH_MOTOR);
		definedYet = true;
	}
	// update winch motor & dashboard
	winchMotor->Set(-power);
	frc::SmartDashboard::PutNumber("Winch Power", power);
}
// reset motor
void Winch::Reset() {
	winchMotor->Set(0.0);
}
