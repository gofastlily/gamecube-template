#include "game.hpp"


// Local source includes
#include "constants.hpp"
#include "game/ship.hpp"


namespace game {


Game::Game() { }


void Game::Init(SDL_Renderer* renderer) {
	player.transform.position.x = SCREEN_WIDTH / 2.0f;
	player.transform.position.y = SCREEN_HEIGHT / 2.0f;
	player.Init(renderer);
	player.active = true;
}


void Game::Update(float delta_seconds, input::Input input) {
	player.Update(delta_seconds, input.gamepads[0]);
	if (input.gamepads[0].button_z.pressed) {
		player.Fire();
	}

	for (int i = 0; i < player.projectile_count; i++) {
		if (!player.projectiles[i].active) continue;
		player.projectiles[i].Update(delta_seconds);
	}
}


void Game::Render(SDL_Renderer* renderer) {
	player.Render(renderer);

	for (int i = 0; i < player.projectile_count; i++) {
		if (!player.projectiles[i].active) continue;
		player.projectiles[i].Render(renderer);
	}
}


}	// namespace game
