#include "AutonomousCommand.h"

#include "DriveByDistance.h"
#include "TurnByAngle.h"
#include "FullAutoPlaceGear.h"

AutonomousCommand::AutonomousCommand(int id) {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	AddSequential(new DriveByDistance(70.0));

	if (id == REDL||id == BLUEL) {
		AddSequential(new TurnByAngle(30.0));
		AddSequential(new DriveByDistance(10.0));
	} else if (id == REDR||id == REDL) {
		AddSequential(new TurnByAngle(-30.0));
		AddSequential(new DriveByDistance(10.0));
	}

	AddSequential(new FullAutoPlaceGear());

}
