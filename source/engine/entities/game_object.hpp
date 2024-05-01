#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "constants.hpp"
#include "engine/entities/entity.hpp"
#include "engine/vector2.hpp"
#include "engine/transform2d.hpp"


namespace engine {


class GameObject : public Entity {
	public:
		GameObject(char* _name = (char*)DEFAULT_GAME_OBJECT_NAME);
		void Update(float);
		char* name;
		float maximum_velocity = DEFAULT_GAME_OBJECT_MAX_SPEED;
		Vector2 velocity;
		Transform2d transform;
};


}	// namespace engine
