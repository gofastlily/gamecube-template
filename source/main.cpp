/***
 * Gamecube Template
 */


// #define DEBUG true
#ifdef DEBUG
#include <debug.h>
#endif


// Linked library includes
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


// Local library includes
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"


// Local source includes
// #include "utils/debug_controller.hpp"
#include "utils/framerate.hpp"


#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480


#define GCN_CONTROLLER_A	SDL_CONTROLLER_BUTTON_A
#define GCN_CONTROLLER_B	SDL_CONTROLLER_BUTTON_X
#define GCN_CONTROLLER_X	SDL_CONTROLLER_BUTTON_B
#define GCN_CONTROLLER_Y	SDL_CONTROLLER_BUTTON_Y


SDL_Renderer *renderer;
SDL_GameController *gamepad;


game::utils::Framerate framerate = game::utils::Framerate();
// game::utils::DebugController debug_controller = game::utils::DebugController();


void init() {
	int status = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER);
	if (status < 0) {
		std::cerr << "SDL could not initialize video and audio! SDL Error: " << SDL_GetError() << std::endl;
	}
}


SDL_GameController *find_controller() {
	int num_joysticks = SDL_NumJoysticks();
	for (int i = 0; i < num_joysticks; i++) {
		if (SDL_IsGameController(i)) {
			return SDL_GameControllerOpen(i);
		}
	}

	return nullptr;
}


void handle_controller_button_down(SDL_Event& event) {
	switch (event.cbutton.button) {
		case GCN_CONTROLLER_X:  // TODO: Remap to Z
			framerate.ToggleShowHide();
			// debug_controller.ToggleShowHide();
			break;
	}
}


void process_input() {
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0) {
		switch (event.type) {
			case SDL_CONTROLLERDEVICEADDED:
				if (!gamepad) {
					gamepad = SDL_GameControllerOpen(event.cdevice.which);
				}
				break;
			case SDL_CONTROLLERDEVICEREMOVED:
				if (gamepad && event.cdevice.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(gamepad))) {
					SDL_GameControllerClose(gamepad);
					gamepad = nullptr;
				}
				gamepad = find_controller();
				break;
			case SDL_CONTROLLERBUTTONDOWN:
				if (gamepad && event.cdevice.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(gamepad))) {
					handle_controller_button_down(event);
				}
				break;
		}
	}
}


void update() {
	ImGui::Begin("Hello, GameCube!");
	ImGui::Text("Written using SDL and Dear ImGui\nfor the Nintendo GameCube");
	ImGui::End();
	// debug_controller.Update();
}


void render(SDL_Renderer* renderer) {
	// Set the draw color...
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	// Clear the screen.
	SDL_RenderClear(renderer);

	// Draw a grey background
	SDL_SetRenderDrawColor(renderer, 100, 100, 100, SDL_ALPHA_OPAQUE);
	SDL_Rect rect = SDL_Rect();
	rect.x = 0;
	rect.y = 0;
	rect.h = SCREEN_HEIGHT;
	rect.w = SCREEN_WIDTH;
	SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderFillRect(renderer, &rect);

	// Draw a teal Triforce
	SDL_SetRenderDrawColor(renderer, 100, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT - 1, SCREEN_WIDTH / 2.0f, 0);
	SDL_RenderDrawLine(renderer, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, SCREEN_WIDTH / 2.0f, 0);
	SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT - 1, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
	SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 4.0f, SCREEN_HEIGHT / 2.0f, SCREEN_WIDTH / 4.0f * 3.0f, SCREEN_HEIGHT / 2.0f);
	SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 4.0f, SCREEN_HEIGHT / 2.0f, SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - 1);
	SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - 1, SCREEN_WIDTH / 4.0f * 3.0f, SCREEN_HEIGHT / 2.0f);

	// Debug GUI
	// debug_controller.Display();
	framerate.Display();

	// Dear ImGui should happen right before presenting the render
	ImGui::Render();
	ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
	SDL_RenderPresent(renderer);
}


int SDL_main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	init();

	SDL_Window *window = SDL_CreateWindow(
		"SDL2",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_FULLSCREEN_DESKTOP
	);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	#ifdef DEBUG
	DEBUG_Init(GDBSTUB_DEVICE_USB, 1);	// USBGecko in Slot B
	printf("Waiting for debugger ...\n");
	_break();	// Enters debug stub, required for gdb debugging
	printf("debugger connected ...\n");
	#endif

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;	// Enable Gamepad Controls
	ImGui::StyleColorsDark();
	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer2_Init(renderer);

	gamepad = find_controller();
	// debug_controller.Init(true);

	while (1) {
		// Keep ImGui outside loop functions to allow for ImGui anywhere
		ImGui_ImplSDLRenderer2_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();
		process_input();
		update();
		render(renderer);
		framerate.Calculate();
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	exit(0);	// Use exit() to exit a program, do not use 'return' from main()
}
