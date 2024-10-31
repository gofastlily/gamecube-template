#include "debug_controller.hpp"


// Linked library includes
#include <SDL2/SDL_image.h>


// Local library includes
#include "constants.hpp"


// Local asset includes
#include "debug_controller_outline_png.h"
#include "debug_controller_button_start_png.h"
#include "debug_controller_button_a_png.h"
#include "debug_controller_button_b_png.h"
#include "debug_controller_button_x_png.h"
#include "debug_controller_button_y_png.h"
#include "debug_controller_trigger_l_png.h"
#include "debug_controller_trigger_r_png.h"
#include "debug_controller_button_z_png.h"
#include "debug_controller_direction_up_png.h"
#include "debug_controller_direction_down_png.h"
#include "debug_controller_direction_left_png.h"
#include "debug_controller_direction_right_png.h"
#include "debug_controller_stick_left_png.h"
#include "debug_controller_stick_right_png.h"
#include "signature_white_png.h"


namespace utils {


namespace debug_controllers {


DebugController::DebugController(bool _show) : show(_show) { }


void DebugController::Init(SDL_Renderer* renderer, int index) {
	float x_position = 0.0f;
	float y_position = 0.0f;

	if (index % 2 == 1) {
		x_position += SCREEN_WIDTH / 2.0f;
	}
	if (index > 1) {
		y_position += SCREEN_HEIGHT / 2.0f;
	}

	x_position += ((SCREEN_WIDTH / 2.0f) - 256.0f) / 2.0f;	// Account for actual controller width

	logo = engine::Tex2d(
		IMG_LoadTexture_RW(renderer, SDL_RWFromConstMem(SIGNATURE_WHITE_PNG, SIGNATURE_WHITE_PNG_SIZE), 1),
		x_position + 86.0f, y_position + 66.0f, 0.7f, 0.7f
	);
	outline = engine::Tex2d(
		IMG_LoadTexture_RW(renderer, SDL_RWFromConstMem(DEBUG_CONTROLLER_OUTLINE_PNG, DEBUG_CONTROLLER_OUTLINE_PNG_SIZE), 1),
		x_position + 0.0f, y_position + 0.0f, 1.0f, 1.0f
	);
	button_start.Init(renderer, DEBUG_CONTROLLER_BUTTON_START_PNG, DEBUG_CONTROLLER_BUTTON_START_PNG_SIZE, x_position + 121.0f, y_position + 114.0f);
	button_a.Init(renderer, DEBUG_CONTROLLER_BUTTON_A_PNG, DEBUG_CONTROLLER_BUTTON_A_PNG_SIZE, x_position + 192.0f, y_position + 108.0f);
	button_b.Init(renderer, DEBUG_CONTROLLER_BUTTON_B_PNG, DEBUG_CONTROLLER_BUTTON_B_PNG_SIZE, x_position + 170.0f, y_position + 131.0f);
	button_x.Init(renderer, DEBUG_CONTROLLER_BUTTON_X_PNG, DEBUG_CONTROLLER_BUTTON_X_PNG_SIZE, x_position + 219.0f, y_position + 102.0f);
	button_y.Init(renderer, DEBUG_CONTROLLER_BUTTON_Y_PNG, DEBUG_CONTROLLER_BUTTON_Y_PNG_SIZE, x_position + 185.0f, y_position + 83.0f);
	button_z.Init(renderer, DEBUG_CONTROLLER_BUTTON_Z_PNG, DEBUG_CONTROLLER_BUTTON_Z_PNG_SIZE, x_position + 182.0f, y_position + 42.0f);
	direction_up.Init(renderer, DEBUG_CONTROLLER_DIRECTION_UP_PNG, DEBUG_CONTROLLER_DIRECTION_UP_PNG_SIZE, x_position + 78.0f, y_position + 158.0f);
	direction_down.Init(renderer, DEBUG_CONTROLLER_DIRECTION_DOWN_PNG, DEBUG_CONTROLLER_DIRECTION_DOWN_PNG_SIZE, x_position + 78.0f, y_position + 182.0f);
	direction_left.Init(renderer, DEBUG_CONTROLLER_DIRECTION_LEFT_PNG, DEBUG_CONTROLLER_DIRECTION_LEFT_PNG_SIZE, x_position + 67.0f, y_position + 171.0f);
	direction_right.Init(renderer, DEBUG_CONTROLLER_DIRECTION_RIGHT_PNG, DEBUG_CONTROLLER_DIRECTION_RIGHT_PNG_SIZE, x_position + 89.0f, y_position + 171.0f);
	stick_left.Init(renderer, DEBUG_CONTROLLER_STICK_LEFT_PNG, DEBUG_CONTROLLER_STICK_LEFT_PNG_SIZE, x_position + 17.0f, y_position + 94.0f);
	stick_right.Init(renderer, DEBUG_CONTROLLER_STICK_RIGHT_PNG, DEBUG_CONTROLLER_STICK_RIGHT_PNG_SIZE, x_position + 154.0f, y_position + 163.0f);
	trigger_l.Init(renderer, DEBUG_CONTROLLER_TRIGGER_L_PNG, DEBUG_CONTROLLER_TRIGGER_L_PNG_SIZE, x_position + 13.0f, y_position + 39.5f);
	trigger_r.Init(renderer, DEBUG_CONTROLLER_TRIGGER_R_PNG, DEBUG_CONTROLLER_TRIGGER_R_PNG_SIZE, x_position + 182.0f, y_position + 37.5f);

	stick_left.show = true;
	stick_right.show = true;
	trigger_l.show = true;
	trigger_r.show = true;
}


void DebugController::Update(input::Gamepad gamepad) {
	is_gamepad_connected = gamepad.IsConnected();
	if (!is_gamepad_connected) return;

	trigger_l.y_position_offset = gamepad.trigger_left.value * 12.5f;
	trigger_r.y_position_offset = gamepad.trigger_right.value * 12.5f;
	trigger_l.Update();
	trigger_r.Update();

	button_start.show = gamepad.button_start.held;
	button_a.show = gamepad.button_a.held;
	button_b.show = gamepad.button_b.held;
	button_x.show = gamepad.button_x.held;
	button_y.show = gamepad.button_y.held;
	button_z.show = gamepad.button_z.held;
	button_start.Update();
	button_a.Update();
	button_b.Update();
	button_x.Update();
	button_y.Update();
	button_z.Update();

	direction_up.show = gamepad.dpad_up.held;
	direction_down.show = gamepad.dpad_down.held;
	direction_left.show = gamepad.dpad_left.held;
	direction_right.show = gamepad.dpad_right.held;
	direction_up.Update();
	direction_down.Update();
	direction_left.Update();
	direction_right.Update();

	stick_left.x_position_offset = gamepad.stick_left.x.value * 18.0f;
	stick_left.y_position_offset = gamepad.stick_left.y.value * 18.0f;
	stick_right.x_position_offset = gamepad.stick_right.x.value * 14.0f;
	stick_right.y_position_offset = gamepad.stick_right.y.value * 14.0f;
	stick_left.Update();
	stick_right.Update();

	// if (gamepad.button_a.held) {
	// 	SDL_GameControllerRumble(gamepad.controller, 0xFFFF, 0xFFFF, 25);
	// }
}


void DebugController::Render(SDL_Renderer* renderer) {
	if (!show) return;
	if (!is_gamepad_connected) return;

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
	show = !show;
}


SDL_GameController *DebugController::FindController() {
	int nujoysticks = SDL_NumJoysticks();
	for (int i = 0; i < nujoysticks; i++) {
		if (SDL_IsGameController(i)) {
			return SDL_GameControllerOpen(i);
		}
	}

	return nullptr;
}


}	// namespace debug_controllers


}	// namespace utils
