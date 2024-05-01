#include "physics.hpp"


namespace game {


Physics::Physics() {}


bool Physics::CheckCollisionAABB(SDL_Rect a, SDL_Rect b) {
	// a is above b
	if (a.y >= b.y + b.h) {
		return false;
	}
	// a is below b
	if (a.y + a.h <= b.y) {
		return false;
	}
	// a is to the left of b
	if (a.x + a.w <= b.x) {
		return false;
	}
	// a is to the right of b
	if (a.x >= b.x + b.w) {
		return false;
	}

    return true;
}


}	// namespace game
