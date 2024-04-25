#include "debug_controller_input.hpp"


// Linked library includes
#include <SDL2/SDL_image.h>


// Local library includes
#include "imgui.h"


namespace game {


namespace utils {


DebugControllerInput::DebugControllerInput() { }


void DebugControllerInput::Init(SDL_Renderer* renderer, void* png, int png_size, float _x_position, float _y_position) {
	x_position = _x_position;
	y_position = _y_position;
	texture = Tex2d(
		IMG_LoadTexture_RW(renderer, SDL_RWFromConstMem(png, png_size), 1),
		x_position, y_position, 1.0f, 1.0f
	);
}


void DebugControllerInput::ProcessInput(SDL_Event& event) {
	if (event.cbutton.type) {
		ProcessButtonInput(event);
	} else if (event.caxis.type) {
		ProcessAxisInput(event);
	}
	
}


void DebugControllerInput::ProcessAxisInput(SDL_Event& event) {
	switch (event.cbutton.button) {
		case SDL_CONTROLLER_AXIS_LEFTX:
		case SDL_CONTROLLER_AXIS_RIGHTX:
			x_position_offset = AxisValueWithDeadzone(event.caxis.value) / 4.0f;
			break;
		case SDL_CONTROLLER_AXIS_LEFTY:
		case SDL_CONTROLLER_AXIS_RIGHTY:
			y_position_offset = AxisValueWithDeadzone(event.caxis.value) / 4.0f;
			break;
		case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
		case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
			y_position_offset = AxisValueWithDeadzone(event.caxis.value) / 4.0f;
			break;
	}
}


void DebugControllerInput::ProcessButtonInput(SDL_Event& event) {
	show = event.cbutton.state;
}


void DebugControllerInput::Update() {
	texture.x_position = x_position + x_position_offset;
	texture.y_position = y_position + y_position_offset;
}


void DebugControllerInput::Render(SDL_Renderer* renderer) {
	if (!show) return;;
	texture.Render(renderer);
}


float DebugControllerInput::AxisValueWithDeadzone(float value) {
	if (value > deadzone || value < -deadzone) {
		return value / SDL_JOYSTICK_AXIS_MAX * 100.0f;
	}
	return 0.0f;
}


}	// namespace utils


}	// namespace game
