#include "input/stick.hpp"


// Standard library includes
#include <algorithm>


namespace input {


Stick::Stick() {
	y.inverted = false;
}


void Stick::ProcessInput(SDL_Event& event) {
	switch (event.cbutton.button) {
		case SDL_CONTROLLER_AXIS_LEFTX:
		case SDL_CONTROLLER_AXIS_RIGHTX:
			x.ProcessInput(event);
			break;
		case SDL_CONTROLLER_AXIS_LEFTY:
		case SDL_CONTROLLER_AXIS_RIGHTY:
			y.ProcessInput(event);
			break;
	}

	changed = x.changed || y.changed;
	if (!changed) return;

	angle = atan2(x.value, -y.value) * (180.0f / M_PI);
	magnitude = std::sqrt((x.value * x.value) + (y.value * y.value));
	normalized_magnitude = magnitude;
	if (magnitude > 1.0f) {
		normalized_magnitude = std::min(std::sqrt((x.value * x.value / (magnitude * 2)) + (y.value * y.value / (magnitude * 2))), magnitude);
	}
}


void Stick::ResetState() {
	x.ResetState();
	y.ResetState();
	angle = 0.0f;
	magnitude = 0.0f;
	normalized_magnitude = 0.0f;
}


}	// namespace input
