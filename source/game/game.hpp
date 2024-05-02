#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "input.hpp"


// Game includes
#include "game/ship.hpp"


namespace game {


class Game {
	public:
		Game();
		void Init(SDL_Renderer*);
		void Update(float, input::Input);
		void Render(SDL_Renderer*);
		Ship player;
};


}	// namespace game
