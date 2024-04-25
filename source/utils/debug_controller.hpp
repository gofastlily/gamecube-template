#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "tex_2d.hpp"
#include "debug_controller_input.hpp"


namespace game {


namespace utils {


class DebugController {
	public:
		DebugController();
		void Init(SDL_Renderer*, SDL_GameController*, bool=false);
		void ProcessInput(SDL_Event&);
		void Update();
		void Render(SDL_Renderer*);
		void ToggleShowHide();
		float stick_left_x_offset = 0.0f;
		float stick_left_y_offset = 0.0f;
		float stick_right_x_offset = 0.0f;
		float stick_right_y_offset = 0.0f;
		float deadzone = 1000.0f;
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
	private:
		void HandleButton(SDL_Event&);
		void HandleAxisMotion(SDL_Event&);
		SDL_GameController *FindController();
		SDL_GameController* m_gamepad;
		bool m_show = true;
		SDL_Rect m_texture_rect;
		Tex2d logo;
		Tex2d outline;
};


}	// namespace utils


}	// namespace game
