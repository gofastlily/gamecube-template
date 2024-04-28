#include "game.hpp"


// Local library includes
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"


// Local source includes
#include "utils/utils.hpp"


Game::Game(SDL_Renderer* _renderer, utils::Framerate _framerate) : renderer(_renderer), framerate(_framerate) {
	input = input::Input();
	debug_controllers_manager = utils::debug_controllers::Manager();
	debug_controllers_manager.Init(renderer);
}


void Game::PreLoop() {
	// Keep ImGui outside loop functions to allow for ImGui anywhere
	ImGui_ImplSDLRenderer2_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
	input.ResetButtonStateForAllControllers();
}


void Game::ProcessInput() {
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0) {
		input.ProcessInput(event);
	}
}


void Game::Update() {
	// ImGui::SetNextWindowPos(ImVec2(640 / 2.0 + 10.0, 40.0));
	// ImGui::SetNextWindowSize(ImVec2(640/ 2.0 - 20.0, 480 - 50.0));
	// ImGui::Begin("Hello, GameCube!", nullptr, ImGuiWindowFlags_NoFocusOnAppearing);
	// ImGui::Text("Written using SDL and Dear ImGui\nfor the Nintendo GameCube");
	// ImGui::Separator();
	// ImGui::Text("C++ Standard: %s", utils::Utils::CppStandard());
	// ImGui::End();

	debug_controllers_manager.Update(input);

	if (input.gamepads[0].button_l.held && input.gamepads[0].dpad_up.pressed) {
		framerate.IncrementState();
	}
	if (input.gamepads[0].button_l.held && input.gamepads[0].dpad_down.pressed) {
		debug_controllers_manager.ToggleShowHide();
	}
}


void Game::Render() {
	// Set the draw color
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	// Clear the screen.
	SDL_RenderClear(renderer);

	// Debug GUI
	debug_controllers_manager.Render(renderer);
	framerate.Display();

	// Rendering of Dear ImGui should happen last before SDL presents the render
	ImGui::Render();
	ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
	SDL_RenderPresent(renderer);
}


void Game::PostLoop() { }
