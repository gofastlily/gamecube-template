#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local library includes
#include "constants.hpp"
#include "engine/entities/entity.hpp"
#include "input/gamepad.hpp"


namespace input {


class Input : public engine::Entity {
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
