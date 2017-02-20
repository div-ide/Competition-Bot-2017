#include "DriveByDistance.h"

DriveByDistance::DriveByDistance(double by) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	inches = by;
}

// Called just before this Command runs the first time
void DriveByDistance::Initialize() {
	drivetrain->isInUse = true;
	encoderStart = drivetrain->GetEncoderAverageDistance();
	encoderTarget = encoderStart + inches;
}

// Called repeatedly when this Command is scheduled to run
void DriveByDistance::Execute() {
	if (drivetrain->GetEncoderAverageDistance() < encoderTarget) {
		drivetrain->controlsSwapped = false;
		if (inches > 0) {
			drivetrain->Drive(0.5, 0.2);
		} else {
			drivetrain->Drive(-0.5, 0.0);
		}
	} else {
		drivetrain->Drive(0.0, 0.0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveByDistance::IsFinished() {
	return drivetrain->GetEncoderAverageDistance() >= encoderTarget||!drivetrain->isInUse;
}

// Called once after isFinished returns true
void DriveByDistance::End() {
	drivetrain->Drive(0.0, 0.0);
	drivetrain->isInUse = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveByDistance::Interrupted() {

}
