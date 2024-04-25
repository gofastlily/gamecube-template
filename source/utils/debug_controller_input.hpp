#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "tex_2d.hpp"


namespace game
{


namespace utils
{


class DebugControllerInput {
	public:
		DebugControllerInput();
		void Init(SDL_Renderer*, void*, int, float = 0.0f, float = 0.0f);
		void ProcessInput(SDL_Event&);
		void ProcessAxisInput(SDL_Event&);
		void ProcessButtonInput(SDL_Event&);
		void Update();
		void Render(SDL_Renderer*);
		Tex2d texture;
		float x_position = 0.0f;
		float y_position = 0.0f;
		float x_position_offset = 0.0f;
		float y_position_offset = 0.0f;
		float deadzone = 1000.0f;
		bool show = false;
	private:
		float AxisValueWithDeadzone(float);
};


}	// namespace utils


}	// namespace game
