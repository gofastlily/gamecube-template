#include "debug_controller_input.hpp"


// Linked library includes
#include <SDL2/SDL_image.h>


// Local library includes
#include "imgui.h"


namespace utils {


namespace debug_controllers {


DebugControllerInput::DebugControllerInput() { }


void DebugControllerInput::Init(SDL_Renderer* renderer, const void* png, int png_size, float _x_position, float _y_position) {
	x_position = _x_position;
	y_position = _y_position;
	texture = engine::Tex2d(
		IMG_LoadTexture_RW(renderer, SDL_RWFromConstMem(png, png_size), 1),
		x_position, y_position, 1.0f, 1.0f
	);
}


void DebugControllerInput::Update() {
	texture.transform.position.x = x_position + x_position_offset;
	texture.transform.position.y = y_position + y_position_offset;
}


void DebugControllerInput::Render(SDL_Renderer* renderer) {
	if (!show) return;
	texture.Render(renderer);
}


}	// namespace debug_controllers


}	// namespace utils
