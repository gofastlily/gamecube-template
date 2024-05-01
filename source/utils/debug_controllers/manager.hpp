#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "constants.hpp"
#include "input/input.hpp"
#include "utils/debug_controllers/debug_controller.hpp"


namespace utils {


namespace debug_controllers {


class Manager {
	public:
		Manager(bool=false);
		void Init(SDL_Renderer*);
		void Update(input::Input&);
		void Render(SDL_Renderer*);
		void ToggleShowHide();
		DebugController debug_controllers[CONTROLLER_COUNT];
};


}	// namespace debug_controllers


}	// namespace utils
