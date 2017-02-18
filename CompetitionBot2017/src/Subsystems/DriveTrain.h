#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>

#include <WPILib.h>

class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	bool definedYet;
	RobotDrive* driveBase;
	Encoder* leftEncoder;
	Encoder* rightEncoder;
	ADXRS450_Gyro* gyro;
public:
	DriveTrain();
	void InitDefaultCommand();
	void Drive(double acceleration, double steering);
};

#endif  // DriveTrain_H
