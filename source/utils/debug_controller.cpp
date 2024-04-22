#include "utils/debug_controller.hpp"


// Library includes
#include <grrlib.h>


// Local includes
#include "utils/colors.hpp"


// Controller assets
#include "signature_white_png.h"
#include "debug_controller_outline_png.h"
#include "debug_controller_button_start_png.h"
#include "debug_controller_button_a_png.h"
#include "debug_controller_button_b_png.h"
#include "debug_controller_button_x_png.h"
#include "debug_controller_button_y_png.h"
#include "debug_controller_trigger_l_png.h"
#include "debug_controller_trigger_r_png.h"
#include "debug_controller_trigger_z_png.h"
#include "debug_controller_direction_up_png.h"
#include "debug_controller_direction_down_png.h"
#include "debug_controller_direction_left_png.h"
#include "debug_controller_direction_right_png.h"
#include "debug_controller_stick_left_png.h"
#include "debug_controller_stick_right_png.h"


namespace game {


DebugController::DebugController(bool show) {
	m_show = show;
	m_debug_controller_logo = GRRLIB_LoadTexture(signature_white_png);
	m_debug_controller_outline = GRRLIB_LoadTexture(debug_controller_outline_png);
	m_debug_controller_button_a = GRRLIB_LoadTexture(debug_controller_button_a_png);
	m_debug_controller_button_start = GRRLIB_LoadTexture(debug_controller_button_start_png);
	m_debug_controller_button_b = GRRLIB_LoadTexture(debug_controller_button_b_png);
	m_debug_controller_button_x = GRRLIB_LoadTexture(debug_controller_button_x_png);
	m_debug_controller_button_y = GRRLIB_LoadTexture(debug_controller_button_y_png);
	m_debug_controller_trigger_l = GRRLIB_LoadTexture(debug_controller_trigger_l_png);
	m_debug_controller_trigger_r = GRRLIB_LoadTexture(debug_controller_trigger_r_png);
	m_debug_controller_trigger_z = GRRLIB_LoadTexture(debug_controller_trigger_z_png);
	m_debug_controller_direction_up = GRRLIB_LoadTexture(debug_controller_direction_up_png);
	m_debug_controller_direction_down = GRRLIB_LoadTexture(debug_controller_direction_down_png);
	m_debug_controller_direction_left = GRRLIB_LoadTexture(debug_controller_direction_left_png);
	m_debug_controller_direction_right = GRRLIB_LoadTexture(debug_controller_direction_right_png);
	m_debug_controller_stick_left = GRRLIB_LoadTexture(debug_controller_stick_left_png);
	m_debug_controller_stick_right = GRRLIB_LoadTexture(debug_controller_stick_right_png);
}


void DebugController::Display() {
	if (m_show) {
		u16 buttonsHeld0 = PAD_ButtonsHeld(0);
		GRRLIB_DrawImg(0, 0, m_debug_controller_outline, 0, 1, 1, GRRLIB_WHITE);
		GRRLIB_DrawImg(86, 66, m_debug_controller_logo, 0, 0.7, 0.7, GRRLIB_WHITE);
		GRRLIB_DrawImg(
			stick_left_x_position + stick_left_x_offset,
			stick_left_y_position + stick_left_y_offset,
			m_debug_controller_stick_left, 0, 1, 1, GRRLIB_WHITE
		);
		GRRLIB_DrawImg(
			stick_right_x_position + stick_right_x_offset,
			stick_right_y_position + stick_right_y_offset,
			m_debug_controller_stick_right, 0, 1, 1, GRRLIB_WHITE
		);
		if (buttonsHeld0 & PAD_BUTTON_START) {
			GRRLIB_DrawImg(121, 114, m_debug_controller_button_start, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_A) {
			GRRLIB_DrawImg(192, 108, m_debug_controller_button_a, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_B) {
			GRRLIB_DrawImg(170, 131, m_debug_controller_button_b, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_X) {
			GRRLIB_DrawImg(220, 102, m_debug_controller_button_x, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_Y) {
			GRRLIB_DrawImg(185, 83, m_debug_controller_button_y, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_TRIGGER_L) {
			GRRLIB_DrawImg(13, 39, m_debug_controller_trigger_l, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_TRIGGER_R) {
			GRRLIB_DrawImg(182, 37, m_debug_controller_trigger_r, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_TRIGGER_Z) {
			GRRLIB_DrawImg(182, 42, m_debug_controller_trigger_z, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_UP) {
			GRRLIB_DrawImg(78, 158, m_debug_controller_direction_up, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_DOWN) {
			GRRLIB_DrawImg(78, 182, m_debug_controller_direction_down, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_LEFT) {
			GRRLIB_DrawImg(67, 171, m_debug_controller_direction_left, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_RIGHT) {
			GRRLIB_DrawImg(89, 171, m_debug_controller_direction_right, 0, 1, 1, GRRLIB_WHITE);
		}
	}
}


void DebugController::ToggleShowHide() {
	m_show = !m_show;
}


}  // namespace game
