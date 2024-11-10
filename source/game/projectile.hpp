#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "tex_2d.hpp"
#include "timer.hpp"
#include "entities/game_object.hpp"
#include "gamepad.hpp"


namespace game {


struct Projectile : public engine::GameObject {
	Projectile();
	void Init(SDL_Renderer*);
	void Update(float);
	void Render(SDL_Renderer*);
	void SetInactive();
	engine::Tex2d texture;
	int lifetime = 0;
	engine::Timer timer;
};


}	// namespace game
