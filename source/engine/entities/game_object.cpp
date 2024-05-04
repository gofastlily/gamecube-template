#include "game_object.hpp"


// Standard library includes
#include <math.h>


namespace engine {


GameObject::GameObject(char* _name) {
	name = _name;
}


void GameObject::Update(float delta_time) {
	if (!active) return;

	if (transform.rotation <= -180.0f) transform.rotation += 360.0f;
	if (transform.rotation >= 180.0f) transform.rotation -= 360.0f;
	if (velocity.x > maximum_velocity) velocity.x = maximum_velocity;
	if (velocity.y <= -180.0f) velocity.y += 360.0f;
	if (velocity.y >= 180.0f) velocity.y -= 360.0f;
	transform.position.x += sin(velocity.y * M_PI / 180.0f) * velocity.x * delta_time;
	transform.position.y -= cos(velocity.y * M_PI / 180.0f) * velocity.x * delta_time;
}


}	// namespace engine
