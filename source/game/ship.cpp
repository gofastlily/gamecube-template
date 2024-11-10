#include "ship.hpp"


// Standard library includes
#include <cmath>


// Linked library includes
#include <SDL2/SDL_image.h>


// Local source includes
#include "utils.hpp"


// Local asset includes
#include "cockpit_png.h"
#include "thruster_left_png.h"
#include "thruster_right_png.h"
#include "ship.hpp"


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
	
	for (int i = 0; i < projectile_count; i++) {
		projectiles.push_back(Projectile());
		projectiles[i].Init(renderer);
	}

	maximum_velocity = PLAYER_MAXIMUM_VELOCITY;
}


void Ship::Update(float delta_time, input::Gamepad gamepad) {
	engine::GameObject::Update(delta_time);

	if (gamepad.stick_right.magnitude > 0) {
		transform.rotation = gamepad.stick_right.angle;
	}

	velocity.x = gamepad.stick_left.normalized_magnitude * maximum_velocity;
	velocity.y = gamepad.stick_left.angle;

	if (fire_rate_timer > 0.0f) {
		fire_rate_timer -= delta_time;
	}
}


void Ship::Render(SDL_Renderer* renderer) {
	cockpit_texture.transform.position.x = transform.position.x;
	cockpit_texture.transform.position.y = transform.position.y;
	cockpit_texture.transform.rotation = transform.rotation;
	thruster_left_texture.transform.position.x = transform.position.x;
	thruster_left_texture.transform.position.y = transform.position.y;
	thruster_left_texture.transform.rotation = transform.rotation;
	thruster_right_texture.transform.position.x = transform.position.x;
	thruster_right_texture.transform.position.y = transform.position.y;
	thruster_right_texture.transform.rotation = transform.rotation;
	cockpit_texture.Render(renderer);
	thruster_left_texture.Render(renderer);
	thruster_right_texture.Render(renderer);
}


void Ship::Fire() {
	if (fire_rate_timer > 0.0f) return;
	if (projectiles[projectiles_fired % projectile_count].active) return;

	fire_rate_timer = fire_rate;

	Projectile& projectile = projectiles[projectiles_fired % projectile_count];
	projectiles_fired++;
	projectile.velocity.x = PLAYER_PROJECTILE_VELOCITY;
	projectile.velocity.y = transform.rotation;
	engine::Vector2 point = utils::Utils::PointOnCircle(projectile.velocity.y, 30.0f);
	projectile.transform.position.x = point.x + transform.position.x - 6.0f;
	projectile.transform.position.y = point.y + transform.position.y - 6.0f;
	projectile.lifetime = 6000;
	projectile.active = true;
	projectile.timer.Start();
}


} // namespace game
