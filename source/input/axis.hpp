#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local library includes
#include "constants.hpp"


namespace input {


class Axis {
	public:
		Axis();
		void ProcessInput(SDL_Event&);
		void ResetState();
		float RawAxisValueWithDeadzone(float);
		float value = 0.0f;
		float previous_value = 0.0f;
		float deadzone = DEFAULT_DEADZONE;
		float minimum_limit = 0.0f;
		float maximum_limit = 100.0f;
		bool changed = false;
		bool inverted = false;
};


}	// namespace input
