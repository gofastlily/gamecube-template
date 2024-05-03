#pragma once


// Local library includes
#include "input/axis.hpp"


namespace input {


class Stick {
	public:
		Stick();
		void ProcessInput(SDL_Event&);
		void ResetState();
		Axis x;
		Axis y;
		float angle = 0.0f;
		float magnitude = 0.0f;
		bool changed = false;
};


}	// namespace input
