#include "OI.h"

#include "Commands/ToggleGear.h"
#include "Commands/ClimbRope.h"
#include "Commands/StopClimbingRope.h"
#include "Commands/SwapJoystick.h"

OI::OI() {
	stick = new frc::Joystick(0);
	btn1 = new frc::JoystickButton(stick, 1);   // Toggle Gear Sleeve
	btn2 = new frc::JoystickButton(stick, 8);   // P: Climb @ 100%. R: "Stop" Climb @ 0%
	btn7 = new frc::JoystickButton(stick, 7);   // Swap joystick controls
	btn1->WhenPressed(new ToggleGear());
	btn2->WhenPressed(new ClimbRope());
	btn2->WhenReleased(new StopClimbingRope());
	btn7->WhenPressed(new SwapJoystick());
}

Joystick* OI::GetJoystick() {
	return stick;
}
