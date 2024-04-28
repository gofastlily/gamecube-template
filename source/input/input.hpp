#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local library includes
#include "input/gamepad.hpp"


#define CONTROLLER_COUNT	4


namespace input {


class Input {
	public:
		Input();
		void ProcessInputs();
		void ProcessInput(SDL_Event&);
		void ProcessControllerConnected(SDL_Event&);
		void ProcessControllerDisconnected(SDL_Event&);
		void ConnectAllControllers();
		SDL_GameController* FindNextController();
		void ResetButtonStateForAllControllers();
		Gamepad gamepads[CONTROLLER_COUNT];
};


}	// namespace input
