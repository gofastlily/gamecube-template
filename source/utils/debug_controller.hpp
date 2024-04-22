#ifndef UTILS_DEBUG_CONTROLLER_HPP
#define UTILS_DEBUG_CONTROLLER_HPP 1


// Library includes
#include <grrlib.h>


namespace game {


class DebugController {
	public:
		DebugController(bool=false);
		void Display();
		void Init();
		void ToggleShowHide();
		f32 stick_left_x_offset = 0.0f;
		f32 stick_left_y_offset = 0.0f;
		f32 stick_right_x_offset = 0.0f;
		f32 stick_right_y_offset = 0.0f;
	private:
		bool m_show;
		GRRLIB_texImg* m_debug_controller_logo;
		GRRLIB_texImg* m_debug_controller_outline;
		GRRLIB_texImg* m_debug_controller_button_a;
		GRRLIB_texImg* m_debug_controller_button_start;
		GRRLIB_texImg* m_debug_controller_button_b;
		GRRLIB_texImg* m_debug_controller_button_x;
		GRRLIB_texImg* m_debug_controller_button_y;
		GRRLIB_texImg* m_debug_controller_trigger_l;
		GRRLIB_texImg* m_debug_controller_trigger_r;
		GRRLIB_texImg* m_debug_controller_trigger_z;
		GRRLIB_texImg* m_debug_controller_direction_up;
		GRRLIB_texImg* m_debug_controller_direction_down;
		GRRLIB_texImg* m_debug_controller_direction_left;
		GRRLIB_texImg* m_debug_controller_direction_right;
		GRRLIB_texImg* m_debug_controller_stick_left;
		GRRLIB_texImg* m_debug_controller_stick_right;
		f32 stick_left_x_position = 17.0f;
		f32 stick_left_y_position = 94.0f;
		f32 stick_right_x_position = 154.0f;
		f32 stick_right_y_position = 163.0f;
};


}  // namespace game


#endif  // UTILS_DEBUG_CONTROLLER_HPP
