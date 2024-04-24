#pragma once


// Linked library includes
#include <SDL2/SDL.h>


namespace game {


namespace utils {


class DebugController {
	public:
		DebugController();
		void Display();
		void Init(bool=false);
		void Update();
		void ToggleShowHide();
		float stick_left_x_offset = 0.0f;
		float stick_left_y_offset = 0.0f;
		float stick_right_x_offset = 0.0f;
		float stick_right_y_offset = 0.0f;
	private:
		SDL_GameController *FindController();
		SDL_GameController* m_gamepad;
		bool m_show = true;
		// GRRLIB_texImg* m_debug_controller_logo;
		// GRRLIB_texImg* m_debug_controller_outline;
		// GRRLIB_texImg* m_debug_controller_button_a;
		// GRRLIB_texImg* m_debug_controller_button_start;
		// GRRLIB_texImg* m_debug_controller_button_b;
		// GRRLIB_texImg* m_debug_controller_button_x;
		// GRRLIB_texImg* m_debug_controller_button_y;
		// GRRLIB_texImg* m_debug_controller_trigger_l;
		// GRRLIB_texImg* m_debug_controller_trigger_r;
		// GRRLIB_texImg* m_debug_controller_trigger_z;
		// GRRLIB_texImg* m_debug_controller_direction_up;
		// GRRLIB_texImg* m_debug_controller_direction_down;
		// GRRLIB_texImg* m_debug_controller_direction_left;
		// GRRLIB_texImg* m_debug_controller_direction_right;
		// GRRLIB_texImg* m_debug_controller_stick_left;
		// GRRLIB_texImg* m_debug_controller_stick_right;
		float stick_left_x_position = 17.0f;
		float stick_left_y_position = 94.0f;
		float stick_right_x_position = 154.0f;
		float stick_right_y_position = 163.0f;
};


}	// namespace utils


}	// namespace game
