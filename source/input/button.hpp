#pragma once


// Linked library includes
#include <SDL2/SDL.h>


namespace input {


class Button {
	public:
		Button();
		void ProcessInput(SDL_Event&);
		void ResetState();
		bool pressed = false;
		bool released = false;
		bool held = false;
};


}	// namespace input
