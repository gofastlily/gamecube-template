#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local library includes
#include "imgui.h"


// Local source includes
#include "input/input.hpp"
#include "utils/framerate.hpp"
#include "utils/debug_controllers/manager.hpp"


class Game {
	public:
		Game(SDL_Renderer*);
		void PreLoop();
		void ProcessInput();
		void Update();
		void Render();
		void PostLoop();
		SDL_Renderer *renderer;
		SDL_GameController *gamepad;
		input::Input input;
		utils::Framerate framerate;
		utils::debug_controllers::Manager debug_controllers_manager;
};
