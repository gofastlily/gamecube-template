#pragma once


// Local source includes
#include "entities/entity.hpp"


namespace engine {


struct Vector2 : public Entity {
	Vector2() {};
	Vector2(float x, float y) : x(x), y(y) {};
	float x = 0.0f;
	float y = 0.0f;
};


}	// namespace engine
