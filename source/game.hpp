#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local library includes
#include "imgui.h"


// Local source includes
#include "input/input.hpp"
#include "utils/framerate.hpp"


class Game {
	public:
		Game(SDL_Renderer*, input::Input);
		void Update();
		void Render();
		SDL_Renderer *renderer;
		SDL_GameController *gamepad;
		input::Input input;
};
