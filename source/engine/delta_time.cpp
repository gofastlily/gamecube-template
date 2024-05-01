#include "delta_time.hpp"


// Linked library includes
#include <SDL2/SDL_timer.h>


namespace engine {


DeltaTime::DeltaTime() {}


void DeltaTime::Update() {
	last = now;
	now = SDL_GetPerformanceCounter();
	performance_frequency = SDL_GetPerformanceFrequency();
	delta_in_seconds = (now - last) / (float)performance_frequency;
	delta_in_milliseconds = delta_in_seconds * 1000;
}


}	// namespace engine
