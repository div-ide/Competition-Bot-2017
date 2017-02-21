#ifndef GearSleeve_H
#define GearSleeve_H

#include <Commands/Subsystem.h>

#include <WPILib.h>

class GearSleeve : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	bool definedYet = false;
	bool isUp = false;
	bool isUpStatus = false;
	bool isLoaded = false;
	//double downPoint = 0.8;
	//double upPoint = 0.2;
	double upPower = 0.9;
	double downPower = -0.9;
	frc::Servo* gearServo;
	frc::DigitalInput* loadedSwitch;
	frc::DigitalInput* upLimit;
public:
	GearSleeve();
	void InitDefaultCommand();
	void Toggle();
	void Raise();
	bool CheckLoadedStatus();
	void Reset();
};

#endif  // GearSleeve_H
