#pragma once


// Local source includes
#include "engine/vector2.hpp"


namespace engine {


struct Transform2d {
	Vector2 position = Vector2();
	float rotation = 0.0f;
	Vector2 scale = Vector2(1.0f, 1.0f);
};


}	// namespace engine
