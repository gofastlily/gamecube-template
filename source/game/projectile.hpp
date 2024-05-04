#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "engine/tex_2d.hpp"
#include "engine/timer.hpp"
#include "engine/entities/game_object.hpp"
#include "input/gamepad.hpp"


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
