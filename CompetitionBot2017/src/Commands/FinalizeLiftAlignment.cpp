#include "FinalizeLiftAlignment.h"
#include "DriveWithJoystick.h"

FinalizeLiftAlignment::FinalizeLiftAlignment() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void FinalizeLiftAlignment::Initialize() {
	drivetrain->controlsSwapped = false;
}

// Called repeatedly when this Command is scheduled to run
void FinalizeLiftAlignment::Execute() {
	drivetrain->isInUse = true;
	double s = 0.0;
	double a = 0.0;
	if (drivetrain->targetFound) {
		if (drivetrain->targetCenter < -5.0) {
			s = 0.45;
			a = 0.05;
		} else if (drivetrain->targetCenter > 5.0) {
			s = -0.45;
			a = 0.05;
		}
		if (drivetrain->targetRange > 5.0) {
			a += 0.47;
		} else {
			a = 0.0;
		}
		drivetrain->Drive(a, s);

	}
}

// Make this return true when this Command no longer needs to run execute()
bool FinalizeLiftAlignment::IsFinished() {
	bool isDone = (drivetrain->targetFound&&drivetrain->targetCenter>=-5.0&&drivetrain->targetCenter<=5.0&&drivetrain->targetRange<=5.0)||(!drivetrain->targetFound);
	frc::SmartDashboard::PutBoolean("Target Aligned", isDone);
	return isDone||!drivetrain->isInUse;
}

// Called once after isFinished returns true
void FinalizeLiftAlignment::End() {
	drivetrain->Drive(0.0, 0.0);
	drivetrain->isInUse = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FinalizeLiftAlignment::Interrupted() {

}
