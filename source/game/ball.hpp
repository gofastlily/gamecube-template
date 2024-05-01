#pragma once


// Local source includes
#include "constants.hpp"
#include "paddle.hpp"


namespace game {


class Ball : public engine::GameObject {
	public:
		Ball(char* _name = (char*)DEFAULT_BALL_NAME);
		void Update(float);
		void Reset();
		float PaddleCollisionAngle(Paddle&);
		float size = DEFAULT_BALL_SIZE;
		SDL_Rect collider;
};


}	// namespace game
