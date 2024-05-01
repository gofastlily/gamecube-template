#pragma once


// Linked library includes
#include <SDL2/SDL.h>


namespace game {


class Physics {
	public:
		Physics();
		static bool CheckCollisionAABB(SDL_Rect a, SDL_Rect b);
};


}	// namespace game
