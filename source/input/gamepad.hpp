#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local library includes
#include "input/button.hpp"


#define GCN_CONTROLLER_BUTTON_START	SDL_CONTROLLER_BUTTON_START
#define GCN_CONTROLLER_BUTTON_A		SDL_CONTROLLER_BUTTON_A
#define GCN_CONTROLLER_BUTTON_B		SDL_CONTROLLER_BUTTON_X
#define GCN_CONTROLLER_BUTTON_L		SDL_CONTROLLER_BUTTON_LEFTSHOULDER
#define GCN_CONTROLLER_BUTTON_R		SDL_CONTROLLER_BUTTON_RIGHTSHOULDER
#define GCN_CONTROLLER_BUTTON_X		SDL_CONTROLLER_BUTTON_B
#define GCN_CONTROLLER_BUTTON_Y		SDL_CONTROLLER_BUTTON_Y
#define GCN_CONTROLLER_BUTTON_Z		SDL_CONTROLLER_BUTTON_BACK
#define GCN_CONTROLLER_DPAD_UP		SDL_CONTROLLER_BUTTON_DPAD_UP
#define GCN_CONTROLLER_DPAD_DOWN	SDL_CONTROLLER_BUTTON_DPAD_DOWN
#define GCN_CONTROLLER_DPAD_LEFT	SDL_CONTROLLER_BUTTON_DPAD_LEFT
#define GCN_CONTROLLER_DPAD_RIGHT	SDL_CONTROLLER_BUTTON_DPAD_RIGHT


#define DEFAULT_DEADZONE 1000.0f


namespace input {


class Gamepad {
	public:
		Gamepad();
		void ProcessInput(SDL_Event&);
		void ProcessAxisInput(SDL_Event&);
		void ProcessButtonInput(SDL_Event&);
		float AxisValueWithDeadzone(float);
		int InstanceID();
		bool CheckEventMatchesController(SDL_Event&);
		void Connect(SDL_GameController* controller);
		void Disconnect();
		void ResetButtonStates();
		bool IsConnected();
		SDL_GameController* controller;

		// Buttons
		Button button_start;
		Button button_a;
		Button button_b;
		Button button_l;
		Button button_r;
		Button button_x;
		Button button_y;
		Button button_z;
		Button dpad_up;
		Button dpad_down;
		Button dpad_left;
		Button dpad_right;

		// Axes
		float stick_left_x = 0.0f;
		float stick_left_y = 0.0f;
		float stick_left_angle = 0.0f;
		float stick_left_magnitude = 0.0f;
		float stick_right_x = 0.0f;
		float stick_right_y = 0.0f;
		float stick_right_angle = 0.0f;
		float stick_right_magnitude = 0.0f;
		float trigger_left = 50.0f;
		float trigger_right = 50.0f;
		float deadzone = DEFAULT_DEADZONE;
		float deadzone_stick_left_x = deadzone;
		float deadzone_stick_left_y = deadzone;
		float deadzone_stick_right_x = deadzone;
		float deadzone_stick_right_y = deadzone;
		float deadzone_trigger_left = deadzone;
		float deadzone_trigger_right = deadzone;
};


}	// namespace input
