#include "input/stick.hpp"


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
	angle = atan2(x.value, -y.value) * (180.0f / M_PI);
	magnitude = abs(hypot(0 - x.value, 0 - y.value));
	changed = x.changed || y.changed;
}


void Stick::ResetState() {
	x.ResetState();
	y.ResetState();
	angle = 0.0f;
	magnitude = 0.0f;
}


}	// namespace input