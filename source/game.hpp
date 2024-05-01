#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "engine/text.hpp"
#include "game/ball.hpp"
#include "game/paddle.hpp"
#include "input/input.hpp"


namespace game {


class Game {
	public:
		Game();
		void Init(SDL_Renderer*);
		void Update(float, input::Input);
		void Render(SDL_Renderer*);
		void AIMovePaddleLeft();
		void AIMovePaddleRight();
		float AIMovePaddleTowardsBall(game::Paddle);
		float AIMovePaddleTowardsCenter(game::Paddle);
		game::Paddle paddle_left;
		game::Paddle paddle_right;
		game::Ball ball;
		engine::Text score_left;
		engine::Text score_right;
		input::Gamepad ai_left_gamepad;
		input::Gamepad ai_right_gamepad;
};


}	// namespace game
