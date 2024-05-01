/***
 * Gamecube Template
 */


// Standard library includes
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


// Linked library includes
#include <ogc/system.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


// Local library includes
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"


// Local source includes
#include "constants.hpp"
#include "engine/delta_time.hpp"
#include "engine/text.hpp"
#include "game/game.hpp"
#include "input/input.hpp"
#include "utils/framerate.hpp"
#include "utils/utils.hpp"
#include "utils/debug_controllers/manager.hpp"


// Local asset includes
#include "josefin_sans_regular_ttf.h"
#include "pong_score_ttf.h"


int SDL_main(int argc, char **argv) {
	(void) argc;
	(void) argv;


	// Redirect stdio and stderr to UART
	SYS_STDIO_Report(true);
	printf("Starting game\r");


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
	io.ConfigFlags |= ImGuiConfigFlags_NoMouse;	// Disable mouse input
	ImGui::StyleColorsDark();
	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer2_Init(renderer);


	// Initialize Game
	input::Input input = input::Input();
	game::Game game = game::Game();
	game.Init(renderer);


	// Initialize Utilities
	utils::Framerate framerate = utils::Framerate(io);
	framerate.state = FRAEMRATE_STATE_HIDDEN;
	utils::debug_controllers::Manager debug_controllers_manager = utils::debug_controllers::Manager();
	debug_controllers_manager.Init(renderer);
	bool show_main_debug_ui = false;
	bool show_debug_zones = false;


	SDL_RWops* font_raw = SDL_RWFromConstMem(josefin_sans_regular_ttf, josefin_sans_regular_ttf_size);
	TTF_Font* font = TTF_OpenFontRW(font_raw, 1, 20);
	engine::Text help_text_movement = engine::Text(
		renderer,
		"  Up and Down on the Left   Stick moves your Paddle",
		font,
		SDL_Color(220, 220, 220),
		SCREEN_WIDTH / 10.0f * 8.0f
	);
	engine::Text help_text_turbo = engine::Text(
		renderer,
		"B enables Turbo Mode,   but at what cost?     ",
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
			ImGui::SetNextWindowPos(ImVec2(SCREEN_WIDTH / 8.0f, SCREEN_HEIGHT / 8.0f));
			ImGui::SetNextWindowSize(ImVec2(SCREEN_WIDTH / 4.0f * 3.0f, SCREEN_HEIGHT / 4.0f * 3.0f));
			ImGui::Begin("Ponglike", nullptr, ImGuiWindowFlags_NoFocusOnAppearing);
			ImGui::Text("Hold L and press D-Pad Left to hide this window");
			ImGui::Separator();
			ImGui::Text("Score: %s v %s", game.score_left.value.c_str(), game.score_right.value.c_str());
			ImGui::Separator();
			ImGui::Text("Game Object: %i", game.paddle_left.id);
			ImGui::Text("Name: %s", game.paddle_left.name);
			ImGui::Text("Speed and Direction: %.1f/%.1f, %.1f", game.paddle_left.velocity.x, game.paddle_left.maximum_velocity, game.paddle_left.velocity.y);
			ImGui::Text("Position: (%.2f, %.2f)", game.paddle_left.transform.position.x, game.paddle_left.transform.position.y);
			ImGui::Separator();
			ImGui::Text("Game Object: %i", game.paddle_right.id);
			ImGui::Text("Name: %s", game.paddle_right.name);
			ImGui::Text("Speed and Direction: %.1f/%.1f, %.1f", game.paddle_right.velocity.x, game.paddle_right.maximum_velocity, game.paddle_right.velocity.y);
			ImGui::Text("Position: (%.2f, %.2f)", game.paddle_right.transform.position.x, game.paddle_right.transform.position.y);
			ImGui::Separator();
			ImGui::Text("Game Object: %i", game.ball.id);
			ImGui::Text("Name: %s", game.ball.name);
			ImGui::Text("Speed and Direction: %.1f/%.1f, %.1f", game.ball.velocity.x, game.ball.maximum_velocity, game.ball.velocity.y);
			ImGui::Text("Position: (%.2f, %.2f)", game.ball.transform.position.x, game.ball.transform.position.y);
			ImGui::End();
		}


		// Clear the screen to render this frame
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		// Render here
		game.Render(renderer);


		if (input.gamepads[0].button_l.held && input.gamepads[0].dpad_right.pressed) {
			show_debug_zones = !show_debug_zones;
		}
		if (show_debug_zones) {
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
			SDL_SetRenderDrawColor(renderer, 0xDD, 0xDD, 0xDD, 0x77);
			SDL_RenderFillRect(renderer, &game.paddle_left.zone_up);
			SDL_RenderFillRect(renderer, &game.paddle_left.zone_down);
			SDL_RenderFillRect(renderer, &game.paddle_left.zone_right);
			SDL_RenderFillRect(renderer, &game.paddle_right.zone_up);
			SDL_RenderFillRect(renderer, &game.paddle_right.zone_down);
			SDL_RenderFillRect(renderer, &game.paddle_right.zone_left);
		}


		debug_controllers_manager.Render(renderer);


		// Debug ui prompt text here
		help_text_movement.rect.x = SCREEN_WIDTH / 2.0f - help_text_movement.surface->w / 2.0f;
		help_text_movement.rect.y = SCREEN_HEIGHT / 10.0f * 8.5f;
		help_text_movement.rect.w = help_text_movement.surface->w;
		help_text_movement.rect.h = help_text_movement.surface->h;
		help_text_movement.Render();

		help_text_turbo.rect.x = SCREEN_WIDTH / 2.0f - help_text_turbo.surface->w / 2.0f;
		help_text_turbo.rect.y = SCREEN_HEIGHT / 10.0f * 9.1f;
		help_text_turbo.rect.w = help_text_turbo.surface->w;
		help_text_turbo.rect.h = help_text_turbo.surface->h;
		help_text_turbo.Render();


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
