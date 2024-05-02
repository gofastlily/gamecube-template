#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "engine/tex_2d.hpp"
#include "engine/entities/game_object.hpp"
#include "input/gamepad.hpp"


namespace game {


struct Ship : public engine::GameObject {
	Ship();
	void Init(SDL_Renderer*);
	void Update(float, input::Gamepad);
	void Render(SDL_Renderer*);
	engine::Tex2d cockpit_texture;
	engine::Tex2d thruster_left_texture;
	engine::Tex2d thruster_right_texture;
};


}	// namespace game
