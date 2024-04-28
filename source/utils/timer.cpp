#include "timer.hpp"


// Standard library includes
#include <algorithm>


// Linked library includes
#include <SDL2/SDL.h>


namespace utils {


Timer::Timer(bool _is_started, bool _is_paused, int _base_ticks, int _ticks_at_pause) : is_started(_is_started), is_paused(_is_paused), base_ticks(_base_ticks), ticks_at_pause(_ticks_at_pause) {}


void Timer::Start() {
	is_started = true;
	is_paused = false;
	base_ticks = SDL_GetTicks();
	ticks_at_pause = 0;
}


void Timer::Stop() {
	is_started = false;
	is_paused = false;
	base_ticks = 0;
	ticks_at_pause = 0;
}


void Timer::Pause() {
	if (!is_started) return;
	if (is_paused) return;

	is_paused = true;
	ticks_at_pause = SDL_GetTicks() - base_ticks;
	base_ticks = 0;
}


void Timer::Unpause() {
	if (!is_started) return;
	if (!is_paused) return;

	base_ticks = SDL_GetTicks() - ticks_at_pause;
	ticks_at_pause = 0;
	is_paused = false;
}


int Timer::Ticks() {
	if (!is_started) return -1;
	else if (is_paused) return ticks_at_pause;
	return SDL_GetTicks() - base_ticks;
}


bool Timer::IsStarted() {
	return is_started;
}


bool Timer::IsPaused() {
	return is_started && is_paused;
}


}	// namespace utils
