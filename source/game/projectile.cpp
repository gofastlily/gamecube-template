#include "projectile.hpp"


// Linked library includes
#include <SDL2/SDL_image.h>


// Local asset includes
#include "simple_png.h"
#include "projectile.hpp"


namespace game {


Projectile::Projectile() {}


void Projectile::Init(SDL_Renderer* renderer) {
	texture = engine::Tex2d(
		IMG_LoadTexture_RW(renderer, SDL_RWFromConstMem(simple_png, simple_png_size), 1),
		transform.position.x, transform.position.y, 0.10f, 0.10f
	);
}


void Projectile::Update(float delta_time) {
	engine::GameObject::Update(delta_time);
	texture.transform.position.x = transform.position.x;
	texture.transform.position.y = transform.position.y;
	texture.transform.rotation = transform.rotation;

	if ((timer.Ticks() >= lifetime)
	|| (transform.position.x + 32 < 0)
	|| (transform.position.y + 32 < 0)
	|| (transform.position.x - 32 > SCREEN_WIDTH)
	|| (transform.position.y - 32 > SCREEN_HEIGHT)) {
		SetInactive();
	}
}


void Projectile::Render(SDL_Renderer* renderer) {
	texture.Render(renderer);
}


void Projectile::SetInactive() {
	timer.Stop();
	active = false;
	velocity.x = 0.0f;
	velocity.y = 0.0f;
	transform.position.x = -128.0f;
	transform.position.y = -128.0f;
}


}	// namespace game
