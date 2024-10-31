#pragma once


// Local source includes
#include "vector2.hpp"
#include "entities/entity.hpp"


namespace engine {


struct Transform2d : public Entity {
	Vector2 position = Vector2();
	float rotation = 0.0f;
	Vector2 scale = Vector2(1.0f, 1.0f);
};


}	// namespace engine
