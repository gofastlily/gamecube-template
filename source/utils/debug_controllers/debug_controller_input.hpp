#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "engine/tex_2d.hpp"


namespace utils {


namespace debug_controllers {


class DebugControllerInput {
	public:
		DebugControllerInput();
		void Init(SDL_Renderer*, const void*, int, float = 0.0f, float = 0.0f);
		void Update();
		void Render(SDL_Renderer*);
		engine::Tex2d texture;
		float x_position = 0.0f;
		float y_position = 0.0f;
		float x_position_offset = 0.0f;
		float y_position_offset = 0.0f;
		float deadzone = 1000.0f;
		bool show = false;
};


}	// namespace debug_controllers


}	// namespace utils
