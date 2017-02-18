#include "OI.h"

#include "Commands/ToggleGear.h"
#include "Commands/ClimbRope.h"
#include "Commands/StopClimbingRope.h"
#include "Commands/HoldRope.h"

OI::OI() {
	stick = new frc::Joystick(0);
	btn1 = new frc::JoystickButton(stick, 1);   // Toggle Gear Sleeve
	btn2 = new frc::JoystickButton(stick, 2);   // P: Climb @ 100%. R: "Hold" Climb @ 20%
	btn7 = new frc::JoystickButton(stick, 7);   // "Stop" Climb @ 0%
	btn11 = new frc::JoystickButton(stick, 11); // Swap joystick controls
	btn1->WhenPressed(new ToggleGear());
	btn2->WhenPressed(new ClimbRope());
	btn2->WhenReleased(new HoldRope());
	btn7->WhenPressed(new StopClimbingRope());
	btn11->WhenPressed(new SwapJoystick());
}

Joystick* OI::GetJoystick() {
	return stick;
}
