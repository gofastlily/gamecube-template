#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "ball.hpp"
#include "input.hpp"
#include "text.hpp"
#include "paddle.hpp"


namespace game {


class Game {
	public:
		Game();
		void Init(SDL_Renderer*);
		void Update(float, input::Input);
		void Render(SDL_Renderer*);
		void AIMovePaddleLeft();
		void AIMovePaddleRight();
		float AIMovePaddleTowardsBall(Paddle);
		float AIMovePaddleTowardsCenter(Paddle);
		Paddle paddle_left;
		Paddle paddle_right;
		Ball ball;
		engine::Text score_left;
		engine::Text score_right;
		input::Gamepad ai_left_gamepad;
		input::Gamepad ai_right_gamepad;
};


}	// namespace game
