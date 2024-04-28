/***
 * Gamecube Template
 */


// #define DEBUG true
#ifdef DEBUG
#include <debug.h>
#endif


// Standard library includes
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


// Linked library includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


// Local library includes
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"


// Local source includes
#include "constants.hpp"
#include "game.hpp"
#include "utils/framerate.hpp"
#include "utils/utils.hpp"
#include "utils/debug_controllers/manager.hpp"


int SDL_main(int argc, char **argv) {
	(void) argc;
	(void) argv;


	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC) < 0) {
		std::cerr << "SDL could not initialize video and audio! SDL Error: " << SDL_GetError() << std::endl;
	}
	IMG_Init(IMG_INIT_PNG);


	// Prepare the SDL Window
	SDL_Window *window = SDL_CreateWindow(
		"SDL2",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		Constants::SCREEN_WIDTH,
		Constants::SCREEN_HEIGHT,
		SDL_WINDOW_FULLSCREEN_DESKTOP
	);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");


	// Prepare the SDL Rendere
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(renderer, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);


	// Initialize Dear ImGui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;	// Enable Gamepad Controls
	ImGui::StyleColorsDark();
	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer2_Init(renderer);


#ifdef DEBUG
	DEBUG_Init(GDBSTUB_DEVICE_USB, 1);	// USBGecko in Slot B
	printf("Waiting for debugger ...\n");	// Explore using Dear ImGui here
	_break();	// Enters debug stub, required for gdb debugging
	printf("debugger connected ...\n");	// Explore using Dear ImGui here
#endif


	// Initialize Game
	input::Input input = input::Input();
	Game game = Game(renderer, input);

	// Initialize Utilities
	utils::Framerate framerate = utils::Framerate(io);
	utils::debug_controllers::Manager debug_controllers_manager = utils::debug_controllers::Manager();
	debug_controllers_manager.Init(renderer);


	while (1) {
		// Keep ImGui outside loop functions to allow for ImGui anywhere
		ImGui_ImplSDLRenderer2_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();

		input.ProcessInputs();

		game.Update();
		// Utils update here
		if (input.gamepads[0].button_l.held && input.gamepads[0].dpad_up.pressed) {
			framerate.IncrementState();
		}
		debug_controllers_manager.Update(input);

		ImGui::SetNextWindowPos(ImVec2(Constants::SCREEN_WIDTH / 6.0f, Constants::SCREEN_HEIGHT / 4.0f));
		ImGui::SetNextWindowSize(ImVec2(Constants::SCREEN_WIDTH / 3.0f * 2.0f, Constants::SCREEN_HEIGHT / 2.0f));
		ImGui::Begin("Hello, GameCube!", nullptr, ImGuiWindowFlags_NoFocusOnAppearing);
		ImGui::Text("Written using SDL2 and Dear ImGui\nfor the Nintendo GameCube");
		ImGui::Separator();
		ImGui::Text("C++ Standard: %s", utils::Utils::CppStandard());
		ImGui::End();
	
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

		game.Render();
		debug_controllers_manager.Render(renderer);
		framerate.Display();

		// Rendering of Dear ImGui should happen last before SDL presents the render
		ImGui::Render();
		ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
		SDL_RenderPresent(renderer);
	}


	// Tear down SDL
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();


	exit(0);	// Bye 🙋🏻‍♀️
}
