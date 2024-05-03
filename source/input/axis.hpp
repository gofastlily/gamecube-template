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
		float AxisValueWithDeadzone(float);
		float value = 0.0f;
		float previous_value = 0.0f;
		float deadzone = DEFAULT_DEADZONE;
		bool changed;
		bool inverted;
};


}	// namespace input
