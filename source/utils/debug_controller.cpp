#include "utils/debug_controller.hpp"


// Linked library includes
#include <SDL2/SDL_image.h>


// Local library includes
#include "imgui.h"


// Local asset includes
#include "debug_controller_outline.hpp"
#include "debug_controller_button_start.hpp"
#include "debug_controller_button_a.hpp"
#include "debug_controller_button_b.hpp"
#include "debug_controller_button_x.hpp"
#include "debug_controller_button_y.hpp"
#include "debug_controller_trigger_l.hpp"
#include "debug_controller_trigger_r.hpp"
#include "debug_controller_button_z.hpp"
#include "debug_controller_direction_up.hpp"
#include "debug_controller_direction_down.hpp"
#include "debug_controller_direction_left.hpp"
#include "debug_controller_direction_right.hpp"
#include "debug_controller_stick_left.hpp"
#include "debug_controller_stick_right.hpp"
#include "signature_white.hpp"


#define GCN_CONTROLLER_BUTTON_A	SDL_CONTROLLER_BUTTON_A
#define GCN_CONTROLLER_BUTTON_B	SDL_CONTROLLER_BUTTON_X
#define GCN_CONTROLLER_BUTTON_X	SDL_CONTROLLER_BUTTON_B
#define GCN_CONTROLLER_BUTTON_Y	SDL_CONTROLLER_BUTTON_Y
#define GCN_CONTROLLER_BUTTON_Z	SDL_CONTROLLER_BUTTON_BACK


namespace game {


namespace utils {


DebugController::DebugController() { }


void DebugController::Init(SDL_Renderer* renderer, SDL_GameController* gamepad, bool show) {
	m_gamepad = FindController();
	m_show = show;

	logo = Tex2d(
		IMG_LoadTexture_RW(renderer, SDL_RWFromConstMem(signature_white_png, signature_white_png_len), 1),
		86.0f, 66.0f, 0.7f, 0.7f
	);
	outline = Tex2d(
		IMG_LoadTexture_RW(renderer, SDL_RWFromConstMem(debug_controller_outline_png, debug_controller_outline_png_len), 1),
		0.0f, 0.0f, 1.0f, 1.0f
	);
	button_start.Init(renderer, debug_controller_button_start_png, debug_controller_button_start_png_len, 121.0f, 114.0f);
	button_a.Init(renderer, debug_controller_button_a_png, debug_controller_button_a_png_len, 192.0f, 108.0f);
	button_b.Init(renderer, debug_controller_button_b_png, debug_controller_button_b_png_len, 170.0f, 131.0f);
	button_x.Init(renderer, debug_controller_button_x_png, debug_controller_button_x_png_len, 219.0f, 102.0f);
	button_y.Init(renderer, debug_controller_button_y_png, debug_controller_button_y_png_len, 185.0f, 83.0f);
	button_z.Init(renderer, debug_controller_button_z_png, debug_controller_button_z_png_len, 182.0f, 42.0f);
	direction_up.Init(renderer, debug_controller_direction_up_png, debug_controller_direction_up_png_len, 78.0f, 158.0f);
	direction_down.Init(renderer, debug_controller_direction_down_png, debug_controller_direction_down_png_len, 78.0f, 182.0f);
	direction_left.Init(renderer, debug_controller_direction_left_png, debug_controller_direction_left_png_len, 67.0f, 171.0f);
	direction_right.Init(renderer, debug_controller_direction_right_png, debug_controller_direction_right_png_len, 89.0f, 171.0f);
	stick_left.Init(renderer, debug_controller_stick_left_png, debug_controller_stick_left_png_len, 17.0f, 94.0f);
	stick_right.Init(renderer, debug_controller_stick_right_png, debug_controller_stick_right_png_len, 154.0f, 163.0f);
	trigger_l.Init(renderer, debug_controller_trigger_l_png, debug_controller_trigger_l_png_len, 13.0f, 27.0f);
	trigger_r.Init(renderer, debug_controller_trigger_r_png, debug_controller_trigger_r_png_len, 182.0f, 24.0f);

	stick_left.show = true;
	stick_right.show = true;
	trigger_l.show = true;
	trigger_r.show = true;
	trigger_l.y_position_offset = 12.5f;
	trigger_r.y_position_offset = 12.5f;
}


void DebugController::ProcessInput(SDL_Event& event) {
	switch (event.type) {
		case SDL_CONTROLLERBUTTONDOWN:
		case SDL_CONTROLLERBUTTONUP:
			HandleButton(event);
			break;
		case SDL_CONTROLLERAXISMOTION:
			HandleAxisMotion(event);
			break;
	}
}


void DebugController::HandleButton(SDL_Event& event) {
	switch (event.cbutton.button) {
		case SDL_CONTROLLER_BUTTON_START:
			button_start.ProcessButtonInput(event);
			break;
		case GCN_CONTROLLER_BUTTON_A:
			button_a.ProcessButtonInput(event);
			break;
		case GCN_CONTROLLER_BUTTON_B:
			button_b.ProcessButtonInput(event);
			break;
		case GCN_CONTROLLER_BUTTON_X:
			button_x.ProcessButtonInput(event);
			break;
		case GCN_CONTROLLER_BUTTON_Y:
			button_y.ProcessButtonInput(event);
			break;
		case GCN_CONTROLLER_BUTTON_Z:
			button_z.ProcessButtonInput(event);
			break;
		case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
			trigger_l.ProcessButtonInput(event);
			break;
		case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
			trigger_r.ProcessButtonInput(event);
			break;
		case SDL_CONTROLLER_BUTTON_DPAD_UP:
			direction_up.ProcessButtonInput(event);
			break;
		case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
			direction_down.ProcessButtonInput(event);
			break;
		case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
			direction_left.ProcessButtonInput(event);
			break;
		case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
			direction_right.ProcessButtonInput(event);
			break;
	}
}


void DebugController::HandleAxisMotion(SDL_Event& event) {
	switch (event.cbutton.button) {
		case SDL_CONTROLLER_AXIS_LEFTX:
		case SDL_CONTROLLER_AXIS_LEFTY:
			stick_left.ProcessAxisInput(event);
			break;
		case SDL_CONTROLLER_AXIS_RIGHTX:
		case SDL_CONTROLLER_AXIS_RIGHTY:
			stick_right.ProcessAxisInput(event);
			break;
		case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
			trigger_l.ProcessAxisInput(event);
			break;
		case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
			trigger_r.ProcessAxisInput(event);
			break;
	}
}


void DebugController::Update() {
	trigger_l.Update();
	trigger_r.Update();

	button_start.Update();
	button_a.Update();
	button_b.Update();
	button_x.Update();
	button_y.Update();
	button_z.Update();

	direction_up.Update();
	direction_down.Update();
	direction_left.Update();
	direction_right.Update();

	stick_left.Update();
	stick_right.Update();
}


void DebugController::Render(SDL_Renderer* renderer) {
	if (!m_show) return;

	// Render triggers first so Z appears above R
	trigger_l.Render(renderer);
	trigger_r.Render(renderer);

	button_start.Render(renderer);
	button_a.Render(renderer);
	button_b.Render(renderer);
	button_x.Render(renderer);
	button_y.Render(renderer);
	button_z.Render(renderer);

	direction_up.Render(renderer);
	direction_down.Render(renderer);
	direction_left.Render(renderer);
	direction_right.Render(renderer);

	logo.Render(renderer);
	outline.Render(renderer);

	// Render sticks last to ensure they appear above the outline
	stick_left.Render(renderer);
	stick_right.Render(renderer);
}


void DebugController::ToggleShowHide() {
	m_show = !m_show;
}


SDL_GameController *DebugController::FindController() {
	int num_joysticks = SDL_NumJoysticks();
	for (int i = 0; i < num_joysticks; i++) {
		if (SDL_IsGameController(i)) {
			return SDL_GameControllerOpen(i);
		}
	}

	return nullptr;
}


}	// namespace utils


}	// namespace game
