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
#include <SDL2/SDL_image.h>


// Local library includes
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"


// Local source includes
#include "game.hpp"
#include "utils/utils.hpp"
#include "utils/debug_controllers/manager.hpp"


#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480


int SDL_main(int argc, char **argv) {
	(void) argc;
	(void) argv;


	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER) < 0) {
		std::cerr << "SDL could not initialize video and audio! SDL Error: " << SDL_GetError() << std::endl;
	}
	IMG_Init(IMG_INIT_PNG);


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


	// Prepare the SDL Rendere
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


#ifdef DEBUG
	DEBUG_Init(GDBSTUB_DEVICE_USB, 1);	// USBGecko in Slot B
	printf("Waiting for debugger ...\n");	// Explore using Dear ImGui here
	_break();	// Enters debug stub, required for gdb debugging
	printf("debugger connected ...\n");	// Explore using Dear ImGui here
#endif


	// Initialize Game
	Game game = Game(renderer);

	while (1) {
		game.PreLoop();
		game.ProcessInput();
		game.Update();
		game.Render();
		game.PostLoop();
	}


	// Tear down SDL
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();


	exit(0);	// Bye 🙋🏻‍♀️
}
