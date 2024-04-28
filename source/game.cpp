#include "game.hpp"


// Local library includes
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"


// Local source includes
#include "utils/utils.hpp"


Game::Game(SDL_Renderer* _renderer, input::Input _input) : renderer(_renderer), input(_input) { }


void Game::Update() {
	// ImGui::SetNextWindowPos(ImVec2(Constants::SCREEN_WIDTH / 4.0f, Constants::SCREEN_HEIGHT / 4.0f));
	// ImGui::SetNextWindowSize(ImVec2(Constants::SCREEN_WIDTH / 2.0f, Constants::SCREEN_HEIGHT / 2.0f));
	// ImGui::Begin("Hello, GameCube!", nullptr, ImGuiWindowFlags_NoFocusOnAppearing);
	// ImGui::Text("Written using SDL and Dear ImGui\nfor the Nintendo GameCube");
	// ImGui::Separator();
	// ImGui::Text("C++ Standard: %s", utils::Utils::CppStandard());
	// ImGui::End();

	ImGui::SetNextWindowPos(ImVec2(Constants::SCREEN_WIDTH / 4.0f, Constants::SCREEN_HEIGHT / 10.0f * 8.5f));
	ImGui::SetNextWindowSize(ImVec2(Constants::SCREEN_WIDTH / 2.0f, Constants::SCREEN_HEIGHT / 10.0f));
	ImGui::Begin(
		"User Prompt", nullptr,
		ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground \
		| ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoFocusOnAppearing
	);
	utils::Utils::ImGuiTextCentered("Press L the D-Pad to toggle debug UI");
	// utils::Utils::ImGuiTextCentered("Press A for Rumble");
	ImGui::End();
}


void Game::Render() {
	// Set the draw color
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	// Clear the screen.
	SDL_RenderClear(renderer);

	// Render game here
}
