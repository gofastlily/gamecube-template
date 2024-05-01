#pragma once


// Linked library includes
#include <SDL2/SDL.h>


namespace engine {


class DeltaTime {
	public:
		DeltaTime();
		void Update();
		int now = SDL_GetPerformanceCounter();
		int last = 0;
		int performance_frequency = 0;
		float delta_in_seconds = 0.0f;
		int delta_in_milliseconds = 0;
};


}	// namespace engine
