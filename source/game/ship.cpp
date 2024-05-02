#include "game/ship.hpp"


// Linked library includes
#include <SDL2/SDL_image.h>


// Local asset includes
#include "cockpit_png.h"
#include "thruster_left_png.h"
#include "thruster_right_png.h"


namespace game {


Ship::Ship() {}


void Ship::Init(SDL_Renderer* renderer) {
	cockpit_texture = engine::Tex2d(
		IMG_LoadTexture_RW(renderer, SDL_RWFromConstMem(cockpit_png, cockpit_png_size), 1),
		transform.position.x, transform.position.y, 0.25f, 0.25f
	);
	cockpit_texture.offset.x = -32;
	cockpit_texture.offset.y = -32;

	thruster_left_texture = engine::Tex2d(
		IMG_LoadTexture_RW(renderer, SDL_RWFromConstMem(thruster_left_png, thruster_left_png_size), 1),
		transform.position.x, transform.position.y, 0.25f, 0.25f
	);
	thruster_left_texture.offset.x = -32;
	thruster_left_texture.offset.y = -32;

	thruster_right_texture = engine::Tex2d(
		IMG_LoadTexture_RW(renderer, SDL_RWFromConstMem(thruster_right_png, thruster_right_png_size), 1),
		transform.position.x, transform.position.y, 0.25f, 0.25f
	);
	thruster_right_texture.offset.x = -32;
	thruster_right_texture.offset.y = -32;
}


void Ship::Update(float delta_time, input::Gamepad gamepad) {
	engine::GameObject::Update(delta_time);
	if (gamepad.stick_right.magnitude > 0) {
		transform.rotation = gamepad.stick_right.angle;
	}
	velocity.x = gamepad.stick_left.normalized_magnitude * maximum_velocity;
	velocity.y = gamepad.stick_left.angle;
	cockpit_texture.transform.position.x = transform.position.x;
	cockpit_texture.transform.position.y = transform.position.y;
	cockpit_texture.transform.rotation = transform.rotation;
	thruster_left_texture.transform.position.x = transform.position.x;
	thruster_left_texture.transform.position.y = transform.position.y;
	thruster_left_texture.transform.rotation = transform.rotation;
	thruster_right_texture.transform.position.x = transform.position.x;
	thruster_right_texture.transform.position.y = transform.position.y;
	thruster_right_texture.transform.rotation = transform.rotation;
}


void Ship::Render(SDL_Renderer* renderer) {
	cockpit_texture.Render(renderer);
	thruster_left_texture.Render(renderer);
	thruster_right_texture.Render(renderer);
}


} // namespace game
