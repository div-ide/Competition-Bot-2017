#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	Joystick* stick;
	JoystickButton* btn1;
	JoystickButton* btn2;
	JoystickButton* btn7;
	JoystickButton* btn6;
public:
	OI();
	Joystick* GetJoystick();
};

#endif  // OI_H
