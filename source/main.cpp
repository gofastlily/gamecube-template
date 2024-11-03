/***
 * Gamecube Template
 */


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
#include "engine/delta_time.hpp"
#include "engine/text.hpp"
#include "game/game.hpp"
#include "utils/framerate.hpp"
#include "utils/utils.hpp"
#include "utils/debug_controllers/manager.hpp"


// Local asset includes
#include "josefin_sans_regular_ttf.h"


int SDL_main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC) < 0) {
		std::cerr << "SDL could not initialize video and audio! SDL Error: " << SDL_GetError() << std::endl;
	}
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();


	// Prepare the SDL Window
	SDL_Window *window = SDL_CreateWindow(
		"SDL2",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_FULLSCREEN_DESKTOP
	);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");


	// Prepare the SDL Renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);


	// Initialize Dear ImGui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;	// Enable Gamepad Controls
	ImGui::StyleColorsDark();
	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer2_Init(renderer);


	// Initialize Game
	input::Input input = input::Input();
	game::Game game = game::Game();
	game.Init(renderer);


	// Initialize Utilities
	utils::Framerate framerate = utils::Framerate(io);
	utils::debug_controllers::Manager debug_controllers_manager = utils::debug_controllers::Manager();
	debug_controllers_manager.Init(renderer);
	bool show_main_debug_ui = true;


	SDL_RWops* font_raw = SDL_RWFromConstMem(josefin_sans_regular_ttf, josefin_sans_regular_ttf_size);
	TTF_Font* font = TTF_OpenFontRW(font_raw, 1, 24);
	engine::Text ui_prompt_text = engine::Text(
		renderer,
		"Press L and the D-Pad to toggle debug UI",
		font,
		SDL_Color(220, 220, 220, 255),
		SCREEN_WIDTH / 10.0f * 8.0f
	);


	// Initalize delta_time right before the game loop
	engine::DeltaTime delta_time = engine::DeltaTime();


	while (1) {
		delta_time.Update();


		// Keep ImGui outside loop functions to allow for ImGui anywhere
		ImGui_ImplSDLRenderer2_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();


		input.ProcessInputs();


		game.Update(delta_time.delta_in_seconds, input);


		if (input.gamepads[0].button_l.held && input.gamepads[0].dpad_up.pressed) {
			framerate.IncrementState();
		}
		debug_controllers_manager.Update(input);


		if (input.gamepads[0].button_l.held && input.gamepads[0].dpad_left.pressed) {
			show_main_debug_ui = !show_main_debug_ui;
		}
		if (show_main_debug_ui) {
			ImGui::SetNextWindowPos(ImVec2(SCREEN_WIDTH / 6.0f, SCREEN_HEIGHT / 6.0f));
			ImGui::SetNextWindowSize(ImVec2(SCREEN_WIDTH / 3.0f * 2.0f, SCREEN_HEIGHT / 3.0f * 2.0f));
			ImGui::Begin("Hello, GameCube!", nullptr, ImGuiWindowFlags_NoFocusOnAppearing);
			ImGui::Text("Written using SDL2 and Dear ImGui\nfor the Nintendo GameCube");
			ImGui::Separator();
			ImGui::Text("C++ Standard: %s", utils::Utils::CppStandard());
			ImGui::End();
		}


		// Clear the screen to render this frame
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		// Render here
		game.Render(renderer);
		debug_controllers_manager.Render(renderer);


		// Debug ui prompt text here
		ui_prompt_text.rect.x = SCREEN_WIDTH / 2.0f - ui_prompt_text.surface->w / 2.0f;
		ui_prompt_text.rect.y = SCREEN_HEIGHT / 10.0f * 9.0f;
		ui_prompt_text.rect.w = ui_prompt_text.surface->w;
		ui_prompt_text.rect.h = ui_prompt_text.surface->h;
		ui_prompt_text.Render();


		framerate.Display();	// Framerate is show here as to appear above any other element

		ImGui::Render();	// Rendering of Dear ImGui must happen last to ensure proper visibility
		ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
		SDL_RenderPresent(renderer);
	}


	// Tear down SDL
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();


	exit(0);	// Bye 🙋🏻‍♀️
}
