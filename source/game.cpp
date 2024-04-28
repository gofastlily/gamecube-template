#include "game.hpp"


// Local library includes
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"


// Local source includes
#include "utils/utils.hpp"


Game::Game(SDL_Renderer* _renderer, input::Input _input) : renderer(_renderer), input(_input) { }


void Game::Update() {
	// ImGui::SetNextWindowPos(ImVec2(Constants::SCREEN_WIDTH / 2.0 + 10.0, 55.0));
	// ImGui::SetNextWindowSize(ImVec2(Constants::SCREEN_WIDTH / 2.0 - 20.0, Constants::SCREEN_HEIGHT - 80.0));
	// ImGui::Begin("Hello, GameCube!", nullptr, ImGuiWindowFlags_NoFocusOnAppearing);
	// ImGui::Text("Written using SDL and Dear ImGui\nfor the Nintendo GameCube");
	// ImGui::Separator();
	// ImGui::Text("C++ Standard: %s", utils::Utils::CppStandard());
	// ImGui::End();
}


void Game::Render() {
	// Set the draw color
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	// Clear the screen.
	SDL_RenderClear(renderer);

	// Render game here
}
