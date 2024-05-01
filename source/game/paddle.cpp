#include "paddle.hpp"


// Standard library includes
#include <math.h>


// Local source includes
#include "constants.hpp"


namespace game {


Paddle::Paddle(char* _name) {
	name = _name;
}


void Paddle::Update(float delta_time, input::Gamepad gamepad) {
	if (gamepad.button_b.pressed) {
		maximum_velocity += 100;
		height -= 50;
	}
	if (gamepad.button_b.released) {
		maximum_velocity -= 100;
		height += 50;
	}

	velocity.x = gamepad.stick_left.magnitude * maximum_velocity;
	velocity.y = gamepad.stick_left.angle;

	GameObject::Update(delta_time);
	collider.x = target_x_position - (width / 2.0f);
	collider.y = transform.position.y - (height / 2.0f);
	collider.w = width;
	collider.h = height;

	transform.position.x = target_x_position;
	transform.position.y = std::max(transform.position.y, (height / 2.0f));
	transform.position.y = std::min(transform.position.y, SCREEN_HEIGHT - (height / 2.0f));

	zone_up.x = transform.position.x - width / 2;
	zone_up.y = 0;
	zone_up.w = width;
	zone_up.h = transform.position.y - height / 2;

	zone_down.x = transform.position.x - width / 2;
	zone_down.y = transform.position.y + height / 2;
	zone_down.w = width;
	zone_down.h = SCREEN_HEIGHT - transform.position.y - height / 2;

	zone_left.x = 0;
	zone_left.y = transform.position.y - height / 2;
	zone_left.w = transform.position.x - width / 2;
	zone_left.h = height;

	zone_right.x = transform.position.x + width / 2;
	zone_right.y = transform.position.y - height / 2;
	zone_right.w = SCREEN_WIDTH - transform.position.x - width / 2;
	zone_right.h = height;
}


}	// namespace game
