#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local library includes
#include "box2d.h"


// Local source includes
#include "input.hpp"


namespace game {


class Game {
	public:
		Game();
		void Init(SDL_Renderer*);
		void Update(float, input::Input);
		void Render(SDL_Renderer*);
		b2World* world;
		b2Body* groundBody;
		b2Body* wallLeftBody;
		b2Body* wallRightBody;
		b2Body* ceilingBody;
		b2Body* dynamicBody;
		int32 velocity_iterations;
		int32 position_iterations;
};


}	// namespace game
