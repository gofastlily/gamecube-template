#include "ball.hpp"


// Standard library includes
#include <math.h>


// Local source includes
#include "constants.hpp"
#include "physics.hpp"
#include "ball.hpp"


namespace game {


Ball::Ball(char* _name) {
	name = _name;
}


void Ball::Update(float delta_time) {
	engine::GameObject::Update(delta_time);
	collider.x = transform.position.x - (size / 2.0f);
	collider.y = transform.position.y - (size / 2.0f);
	collider.w = size;
	collider.h = size;
}


void Ball::Reset() {
	velocity.y = -velocity.y;
	transform.position.x = SCREEN_WIDTH / 2.0f;
	transform.position.y = SCREEN_HEIGHT / 2.0f;
	collider.x = transform.position.x;
	collider.y = transform.position.y;
}


float Ball::PaddleCollisionAngle(Paddle& paddle) {
	float collision_y = (paddle.transform.position.y) - (transform.position.y);
	float max_y = (paddle.height / 2.0f) - (size /2.0f);
	float collision_sign = (0.0f < collision_y) - (collision_y < 0.0f);
    return (75.0f * abs(collision_y) / abs(max_y) * collision_sign);
}


}	// namespace game
