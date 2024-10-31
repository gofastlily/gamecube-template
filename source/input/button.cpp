#include "button.hpp"


namespace input {


Button::Button() { }


void Button::ProcessInput(SDL_Event& event) {
	switch (event.cbutton.state) {
		case SDL_PRESSED:
			pressed = !held;
			released = false;
			held = true;
			break;
		case SDL_RELEASED:
			pressed = false;
			released = held;
			held = false;
			break;
	}
}


void Button::ResetState() {
	pressed = false;
	released = false;
}


}	// namespace input
