#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "input/gamepad.hpp"
#include "engine/tex_2d.hpp"
#include "debug_controller_input.hpp"


namespace utils {


namespace debug_controllers {


class DebugController {
	public:
		DebugController(bool=false);
		void Init(SDL_Renderer*, int);
		void Update(input::Gamepad);
		void Render(SDL_Renderer*);
		void ToggleShowHide();
		SDL_GameController *FindController();
		float stick_left_x_offset = 0.0f;
		float stick_left_y_offset = 0.0f;
		float stick_right_x_offset = 0.0f;
		float stick_right_y_offset = 0.0f;
		float deadzone = 1000.0f;
		int index = -1;
		bool show;
		bool is_gamepad_connected = false;
		SDL_Rect texture_rect;
		engine::Tex2d logo;
		engine::Tex2d outline;
		DebugControllerInput button_start = DebugControllerInput();
		DebugControllerInput button_a = DebugControllerInput();
		DebugControllerInput button_b = DebugControllerInput();
		DebugControllerInput button_x = DebugControllerInput();
		DebugControllerInput button_y = DebugControllerInput();
		DebugControllerInput button_z = DebugControllerInput();
		DebugControllerInput direction_up = DebugControllerInput();
		DebugControllerInput direction_down = DebugControllerInput();
		DebugControllerInput direction_left = DebugControllerInput();
		DebugControllerInput direction_right = DebugControllerInput();
		DebugControllerInput stick_left = DebugControllerInput();
		DebugControllerInput stick_right = DebugControllerInput();
		DebugControllerInput trigger_l = DebugControllerInput();
		DebugControllerInput trigger_r = DebugControllerInput();
};


}	// namespace debug_controllers


}	// namespace utils
