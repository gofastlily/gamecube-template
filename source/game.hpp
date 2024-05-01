#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "input/input.hpp"


namespace game {


class Game {
	public:
		Game();
		void Init();
		void Update(float, input::Input);
		void Render(SDL_Renderer*);
};


}	// namespace game
