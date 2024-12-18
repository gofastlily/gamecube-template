#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "constants.hpp"
#include "entities/entity.hpp"
#include "axis.hpp"
#include "button.hpp"
#include "stick.hpp"


namespace input {


class Gamepad : public engine::Entity {
	public:
		Gamepad();
		void ProcessInput(SDL_Event&);
		void ProcessAxisInput(SDL_Event&);
		void ProcessButtonInput(SDL_Event&);
		int InstanceID();
		bool CheckEventMatchesController(SDL_Event&);
		void Connect(SDL_GameController* controller);
		void Disconnect();
		void ResetAxisStates();
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
		Stick stick_left;
		Stick stick_right;
		Axis trigger_left;
		Axis trigger_right;
};


}	// namespace input
