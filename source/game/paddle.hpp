#pragma once


// Local source includes
#include "constants.hpp"
#include "game_object.hpp"
#include "input.hpp"


namespace game {


class Paddle : public engine::GameObject {
	public:
		Paddle(char* _name = (char*)DEFAULT_PADDLE_NAME);
		void Update(float, input::Gamepad);
		float width = DEFAULT_PADDLE_WIDTH;
		float height = DEFAULT_PADDLE_HEIGHT;
		float target_x_position = 30.0f;
		SDL_Rect collider;
		SDL_Rect zone_up;
		SDL_Rect zone_down;
		SDL_Rect zone_left;
		SDL_Rect zone_right;
};


}	// namespace game
