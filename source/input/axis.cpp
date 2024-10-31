#include "axis.hpp"


// Standard library includes
#include <algorithm>


// Local library includes
#include "utils.hpp"


namespace input {


Axis::Axis() {}


void Axis::ProcessInput(SDL_Event& event) {
	float raw_value = RawAxisValueWithDeadzone(event.caxis.value);
	value = std::min(std::max((std::abs(raw_value) - minimum_limit) / (maximum_limit - minimum_limit), 0.0f), 1.0f) * utils::Utils::SignOfFloat(raw_value);
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


float Axis::RawAxisValueWithDeadzone(float value) {
	if (value > deadzone || value < -deadzone) {
		return value / SDL_JOYSTICK_AXIS_MAX * 100.0f;
	}
	return 0.0f;
}


}	// namespace input
