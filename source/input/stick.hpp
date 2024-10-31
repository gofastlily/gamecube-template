#pragma once


// Local library includes
#include "entities/entity.hpp"
#include "axis.hpp"


namespace input {


class Stick : public engine::Entity {
	public:
		Stick();
		void ProcessInput(SDL_Event&);
		void ResetState();
		Axis x;
		Axis y;
		float angle = 0.0f;
		float magnitude = 0.0f;
		float normalized_magnitude = 0.0f;
		bool changed = false;
};


}	// namespace input
