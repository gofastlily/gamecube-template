#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local library includes
#include "box2d.h"


// Local source includes
#include "input.hpp"
#include "draw_box2d.hpp"


namespace game {


class Game {
	public:
		Game();
		void Init(SDL_Renderer*);
		void Update(float, input::Input);
		void Render(SDL_Renderer*);
		void RenderBoundingBox(SDL_Renderer*, b2Body*);
		b2World* world;
		b2Body* groundBody;
		b2Body* wallLeftBody;
		b2Body* wallRightBody;
		b2Body* ceilingBody;
		b2Body* characterBody;
		int32 velocity_iterations;
		int32 position_iterations;
		int world_height;
		int world_width;
		float world_rendering_scale;
};


}	// namespace game
