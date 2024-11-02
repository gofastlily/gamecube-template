/***
 * Gamecube Template
 */


// Standard library includes
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


// Linked library includes
#include <GL/gl.h>
#include <GL/glu.h>
#include <ogc/system.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


// Local library includes
// #include "imgui.h"
// #include "imgui_impl_sdl2.h"
// #include "imgui_impl_sdlrenderer2.h"


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


// OpenGL test texture
#include "crate.h"

// OpenGL test variables
GLfloat rotation_triangle;
GLfloat rotation_quad;

// OpenGL test light data
GLfloat light_ambient[] = {0.5f, 0.5f, 0.5f, 1.0f};
GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat light_position[] = {0.0f, 5.0f, 0.0f, 1.0f};

// OpenGL test filter and texture metadata
GLuint filter;	// which filter to use
GLuint texture[3];	// storage for textures


void LoadGLTextures() {
	SDL_Surface *texture_image[1];

	texture_image[0] = SDL_LoadBMP_RW(SDL_RWFromConstMem(crate_tex, size_crate_tex), 1);

	// Three different textures to showcase different types of filtering
	glGenTextures(1, &texture[0]);

	// Select the first texture
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	// Nearest filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Generate the first texture
	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture_image[0]->w, texture_image[0]->h, 0, GL_BGR, GL_UNSIGNED_BYTE, texture_image[0]->pixels);

	// // Select the second texture
	// glBindTexture(GL_TEXTURE_2D, texture[1]);
	
	// // Linear filtering
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// // Generate the second texture
	// glTexImage2D(GL_TEXTURE_2D, 0, 3, texture_image[1]->w, texture_image[1]->h, 0, GL_BGR, GL_UNSIGNED_BYTE, texture_image[1]->pixels);

	// // Select the third texture
	// glBindTexture(GL_TEXTURE_2D, texture[2]);
	
	// // Mipmapped filtering
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// // Generate the third texture
	// glTexImage2D(GL_TEXTURE_2D, 0, 3, texture_image[2]->w, texture_image[2]->h, 0, GL_BGR, GL_UNSIGNED_BYTE, texture_image[2]->pixels);
}


void DrawGLScene() {
	// Clear the screen and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset the view
	glLoadIdentity();
	// gluLookAt(
	// 	5, 5, 5,
	// 	0, 0, 0,
	// 	0, 1, 0
	// );
	// glLightfv(GL_LIGHT1, GL_POSITION, light_position);

	// // Select a texture
	// glBindTexture(GL_TEXTURE_2D, texture[filter]);

	// Draw quads for the test crate
	// glBegin(GL_QUADS);

	// // Front face
	// glNormal3f(0.0f, 0.0f, 1.0f);
	// glTexCoord2f(1.0f, 0.0f);
	// glVertex3f(-1.0f, -1.0f, 1.0f);

	// // End drawing quads for the test crate
	// glEnd();

	glTranslatef(-1.5f, 0.0f, -6.0f);

	glRotatef(rotation_triangle, 0.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
		// Top
		glColor3f(0.9f, 0.1f, 0.1f);
		glVertex3f(0.0f,  1.0f, 0.0f);
		// Bottom left
		glColor3f(0.1f, 0.9f, 0.1f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		// Bottom right
		glColor3f(0.1f, 0.1f, 0.9f);
		glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
	glLoadIdentity();

	/* Move Right 3 Units */
	glTranslatef(1.5f, 0.0f, -6.0f);

	glRotatef(rotation_quad, 1.0f, 0.0f, 0.0f);
	glColor3f(0.6f, 0.7f, 0.9f);
	glBegin(GL_QUADS);
		// Top left
		glVertex3f(-1.0f,  1.0f, 0.0f);
		// Top right
		glVertex3f( 1.0f,  1.0f, 0.0f);
		// Bottom right
		glVertex3f( 1.0f, -1.0f, 0.0f);
		// Bottom left
		glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();  

}


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
		SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL
	);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GLContext gl_context = SDL_GL_CreateContext(window);


	// Prepare the SDL Renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);


	// Load textures used by the OpenGL test
	// LoadGLTextures();

	// Configure the Viewport
	glViewport(0, 0, (GLint)SCREEN_WIDTH, (GLint)SCREEN_HEIGHT);

	// Configure the camera
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 100.0f);

	// Switch back to and reset the model view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Enable alpha blending
	// glEnable(GL_BLEND);
	// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// glEnable(GL_TEXTURE_2D);	// Texture mapping
	glShadeModel(GL_SMOOTH);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	// Set up the depth buffer
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	// glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	// glLightfv(GL_LIGHT1, GL_POSITION, light_position);

	// glEnable(GL_LIGHT1);
	// glEnable(GL_LIGHTING);


	// Initialize Dear ImGui
	// IMGUI_CHECKVERSION();
	// ImGui::CreateContext();
	// ImGuiIO& io = ImGui::GetIO(); (void)io;
	// io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;	// Enable Gamepad Controls
	// io.ConfigFlags |= ImGuiConfigFlags_NoMouse;	// Disable mouse input
	// ImGui::StyleColorsDark();
	// ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	// ImGui_ImplSDLRenderer2_Init(renderer);


	// Initialize Game
	input::Input input = input::Input();
	// game::Game game = game::Game();
	// game.Init(renderer);


	// Initialize Utilities
	// utils::Framerate framerate = utils::Framerate(io);
	// utils::debug_controllers::Manager debug_controllers_manager = utils::debug_controllers::Manager();
	// debug_controllers_manager.Init(renderer);
	// bool show_main_debug_ui = false;


	SDL_RWops* font_raw = SDL_RWFromConstMem(josefin_sans_regular_ttf, josefin_sans_regular_ttf_size);
	TTF_Font* font = TTF_OpenFontRW(font_raw, 1, 24);
	// engine::Text ui_prompt_text = engine::Text(
	// 	renderer,
	// 	"Press L and the D-Pad to toggle debug UI",
	// 	font,
	// 	SDL_Color(220, 220, 220, 255),
	// 	SCREEN_WIDTH / 10.0f * 8.0f
	// );


	// Initalize delta_time right before the game loop
	engine::DeltaTime delta_time = engine::DeltaTime();


	while (1) {
		delta_time.Update();


		// Keep ImGui outside loop functions to allow for ImGui anywhere
		// ImGui_ImplSDLRenderer2_NewFrame();
		// ImGui_ImplSDL2_NewFrame();
		// ImGui::NewFrame();


		input.ProcessInputs();


		// game.Update(delta_time.delta_in_seconds, input);
		rotation_triangle += 0.2f;
		rotation_quad -= 0.15f;


		// if (input.gamepads[0].button_l.held && input.gamepads[0].dpad_up.pressed) {
		// 	framerate.IncrementState();
		// }
		// debug_controllers_manager.Update(input);


		// if (input.gamepads[0].button_l.held && input.gamepads[0].dpad_left.pressed) {
		// 	show_main_debug_ui = !show_main_debug_ui;
		// }
		// if (show_main_debug_ui) {
		// 	ImGui::SetNextWindowPos(ImVec2(SCREEN_WIDTH / 6.0f, SCREEN_HEIGHT / 6.0f));
		// 	ImGui::SetNextWindowSize(ImVec2(SCREEN_WIDTH / 3.0f * 2.0f, SCREEN_HEIGHT / 3.0f * 2.0f));
		// 	ImGui::Begin("Hello, GameCube!", nullptr, ImGuiWindowFlags_NoFocusOnAppearing);
		// 	ImGui::Text("Written using OpenGX, SDL2, and Dear ImGui\nfor the Nintendo GameCube");
		// 	ImGui::Separator();
		// 	ImGui::Text("C++ Standard: %s", utils::Utils::CppStandard());
		// 	ImGui::End();
		// }


		// Clear the screen to render this frame
		// SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		// SDL_RenderClear(renderer);

		// Render here
		DrawGLScene();
		// game.Render(renderer);
		// debug_controllers_manager.Render(renderer);


		// Debug ui prompt text here
		// ui_prompt_text.rect.x = SCREEN_WIDTH / 2.0f - ui_prompt_text.surface->w / 2.0f;
		// ui_prompt_text.rect.y = SCREEN_HEIGHT / 10.0f * 9.0f;
		// ui_prompt_text.rect.w = ui_prompt_text.surface->w;
		// ui_prompt_text.rect.h = ui_prompt_text.surface->h;
		// ui_prompt_text.Render();


		// framerate.Display();	// Framerate is show here as to appear above any other element


		// ImGui::Render();	// Rendering of Dear ImGui must happen last to ensure proper visibility
		// ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
		SDL_GL_SwapWindow(window);
		// SDL_RenderPresent(renderer);
	}


	// Tear down SDL
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();


	exit(0);	// Bye 🙋🏻‍♀️
}
