#include "game.hpp"


// Local library includes
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"


// Local source includes
#include "utils/utils.hpp"


namespace game {


Game::Game(SDL_Renderer* _renderer, input::Input _input) : renderer(_renderer), input(_input) { }


void Game::Update() {}


void Game::Render() {
	// Set the draw color
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	// Clear the screen.
	SDL_RenderClear(renderer);

	// Render game here
}


}	// namespace game
