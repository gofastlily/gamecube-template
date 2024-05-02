#include "game.hpp"


namespace game {


Game::Game() { }


void Game::Init(SDL_Renderer* renderer) {
	player.transform.position.x = SCREEN_WIDTH / 2.0f;
	player.transform.position.y = SCREEN_HEIGHT / 2.0f;
	player.Init(renderer);
}


void Game::Update(float delta_seconds, input::Input input) {
	player.Update(delta_seconds, input.gamepads[0]);
}


void Game::Render(SDL_Renderer* renderer) {
	player.Render(renderer);
}


}	// namespace game
