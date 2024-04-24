#include "utils/debug_controller.hpp"


// Linked library includes
#include <SDL2/SDL.h>


// Local library includes
#include "imgui.h"


// Controller assets
// #include "signature_white_png.h"
// #include "debug_controller_outline_png.h"
// #include "debug_controller_button_start_png.h"
// #include "debug_controller_button_a_png.h"
// #include "debug_controller_button_b_png.h"
// #include "debug_controller_button_x_png.h"
// #include "debug_controller_button_y_png.h"
// #include "debug_controller_trigger_l_png.h"
// #include "debug_controller_trigger_r_png.h"
// #include "debug_controller_trigger_z_png.h"
// #include "debug_controller_direction_up_png.h"
// #include "debug_controller_direction_down_png.h"
// #include "debug_controller_direction_left_png.h"
// #include "debug_controller_direction_right_png.h"
// #include "debug_controller_stick_left_png.h"
// #include "debug_controller_stick_right_png.h"


namespace game {


namespace utils {


DebugController::DebugController() { }



void DebugController::Init(bool show) {
	m_gamepad = FindController();
	m_show = show;

	// u8 deadzone = 3;
	// u8 deadzone_stick_left = deadzone;
	// u8 deadzone_stick_right = deadzone;

	// m_debug_controller_logo = GRRLIB_LoadTexture(signature_white_png);
	// m_debug_controller_outline = GRRLIB_LoadTexture(debug_controller_outline_png);
	// m_debug_controller_button_a = GRRLIB_LoadTexture(debug_controller_button_a_png);
	// m_debug_controller_button_start = GRRLIB_LoadTexture(debug_controller_button_start_png);
	// m_debug_controller_button_b = GRRLIB_LoadTexture(debug_controller_button_b_png);
	// m_debug_controller_button_x = GRRLIB_LoadTexture(debug_controller_button_x_png);
	// m_debug_controller_button_y = GRRLIB_LoadTexture(debug_controller_button_y_png);
	// m_debug_controller_trigger_l = GRRLIB_LoadTexture(debug_controller_trigger_l_png);
	// m_debug_controller_trigger_r = GRRLIB_LoadTexture(debug_controller_trigger_r_png);
	// m_debug_controller_trigger_z = GRRLIB_LoadTexture(debug_controller_trigger_z_png);
	// m_debug_controller_direction_up = GRRLIB_LoadTexture(debug_controller_direction_up_png);
	// m_debug_controller_direction_down = GRRLIB_LoadTexture(debug_controller_direction_down_png);
	// m_debug_controller_direction_left = GRRLIB_LoadTexture(debug_controller_direction_left_png);
	// m_debug_controller_direction_right = GRRLIB_LoadTexture(debug_controller_direction_right_png);
	// m_debug_controller_stick_left = GRRLIB_LoadTexture(debug_controller_stick_left_png);
	// m_debug_controller_stick_right = GRRLIB_LoadTexture(debug_controller_stick_right_png);
}


void DebugController::Update() {
	// bool button_z = SDL_GameControllerGetButton(m_gamepad, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER);
}


void DebugController::Display() {
	if (!m_show) return;

	ImGui::SetNextWindowPos(ImVec2(10, 10));
	ImGui::SetNextWindowSize(ImVec2(300, 220));
	ImGui::Begin(
		"Debug Controller", nullptr,
		ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoNav
	);
	ImGui::Text("Debug Controller UI");

	int num_joysticks = SDL_NumJoysticks();
	int num_game_controllers = 0;
	for (int i = 0; i < num_joysticks; i++) {
	    if (SDL_IsGameController(i)) {
	        num_game_controllers++;
	    }
	}
	if (!num_game_controllers) return;
	ImGui::Text("Connected Game Controllers: %d", num_game_controllers);
	ImGui::Text("Controller mappings: %d", SDL_GameControllerNumMappings());

	// if (m_gamepad) {
	// 	ImGui::Text("Left Trigger: %d", );
	// }

	ImGui::End();

	// u16 buttonsHeld0 = PAD_ButtonsHeld(0);
	// GRRLIB_DrawImg(0.0f, 0.0f, m_debug_controller_outline, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE);
	// GRRLIB_DrawImg(86.0f, 66.0f, m_debug_controller_logo, 0.0f, 0.7f, 0.7f, GRRLIB_WHITE);
	// GRRLIB_DrawImg(
	// 	stick_left_x_position + stick_left_x_offset,
	// 	stick_left_y_position + stick_left_y_offset,
	// 	m_debug_controller_stick_left, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE
	// );
	// GRRLIB_DrawImg(
	// 	stick_right_x_position + stick_right_x_offset,
	// 	stick_right_y_position + stick_right_y_offset,
	// 	m_debug_controller_stick_right, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE
	// );
	// if (buttonsHeld0 & PAD_BUTTON_START) {
	// 	GRRLIB_DrawImg(121.0f, 114.0f, m_debug_controller_button_start, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE);
	// }
	// if (buttonsHeld0 & PAD_BUTTON_A) {
	// 	GRRLIB_DrawImg(192.0f, 108.0f, m_debug_controller_button_a, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE);
	// }
	// if (buttonsHeld0 & PAD_BUTTON_B) {
	// 	GRRLIB_DrawImg(170.0f, 131.0f, m_debug_controller_button_b, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE);
	// }
	// if (buttonsHeld0 & PAD_BUTTON_X) {
	// 	GRRLIB_DrawImg(220.0f, 102.0f, m_debug_controller_button_x, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE);
	// }
	// if (buttonsHeld0 & PAD_BUTTON_Y) {
	// 	GRRLIB_DrawImg(185.0f, 83.0f, m_debug_controller_button_y, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE);
	// }
	// if (buttonsHeld0 & PAD_TRIGGER_L) {
	// 	GRRLIB_DrawImg(13.0f, 39.0f, m_debug_controller_trigger_l, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE);
	// }
	// if (buttonsHeld0 & PAD_TRIGGER_R) {
	// 	GRRLIB_DrawImg(182.0f, 37.0f, m_debug_controller_trigger_r, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE);
	// }
	// if (buttonsHeld0 & PAD_TRIGGER_Z) {
	// 	GRRLIB_DrawImg(182.0f, 42.0f, m_debug_controller_trigger_z, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE);
	// }
	// if (buttonsHeld0 & PAD_BUTTON_UP) {
	// 	GRRLIB_DrawImg(78.0f, 158.0f, m_debug_controller_direction_up, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE);
	// }
	// if (buttonsHeld0 & PAD_BUTTON_DOWN) {
	// 	GRRLIB_DrawImg(78.0f, 182.0f, m_debug_controller_direction_down, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE);
	// }
	// if (buttonsHeld0 & PAD_BUTTON_LEFT) {
	// 	GRRLIB_DrawImg(67.0f, 171.0f, m_debug_controller_direction_left, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE);
	// }
	// if (buttonsHeld0 & PAD_BUTTON_RIGHT) {
	// 	GRRLIB_DrawImg(89.0f, 171.0f, m_debug_controller_direction_right, 0.0f, 1.0f, 1.0f, GRRLIB_WHITE);
	// }
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
