#include "input/axis.hpp"


namespace input {


Axis::Axis() {}


void Axis::ProcessInput(SDL_Event& event) {
	value = AxisValueWithDeadzone(event.caxis.value);
	if (inverted) {
		value = -value;
	}
	changed = value != previous_value;
	previous_value = value;
}


void Axis::ResetState() {
	value = 0.0f;
	previous_value = 0.0f;
	changed = false;
}


float Axis::AxisValueWithDeadzone(float value) {
	if (value > deadzone || value < -deadzone) {
		return value / SDL_JOYSTICK_AXIS_MAX * 100.0f;
	}
	return 0.0f;
}


}	// namespace input
