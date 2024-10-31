#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "entities/entity.hpp"


namespace input {


class Button : public engine::Entity {
	public:
		Button();
		void ProcessInput(SDL_Event&);
		void ResetState();
		bool pressed = false;
		bool released = false;
		bool held = false;
};


}	// namespace input
