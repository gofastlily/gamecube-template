#pragma once


// Standard library includes
#include <vector>


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "constants.hpp"
#include "tex_2d.hpp"
#include "entities/game_object.hpp"
#include "gamepad.hpp"


// Game includes
#include "projectile.hpp"


namespace game {


struct Ship : public engine::GameObject {
	Ship();
	void Init(SDL_Renderer*);
	void Update(float, input::Gamepad);
	void Render(SDL_Renderer*);
	void Fire();
	engine::Tex2d cockpit_texture;
	engine::Tex2d thruster_left_texture;
	engine::Tex2d thruster_right_texture;
	std::vector<Projectile> projectiles;
	int projectile_count = PLAYER_PROJECTILE_COUNT;
	int projectiles_fired = 0;
	float fire_rate = PLAYER_FIRE_RATE;
	float fire_rate_timer = 0.0f;
};


}	// namespace game
