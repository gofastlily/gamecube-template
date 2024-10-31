#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local source includes
#include "transform2d.hpp"
#include "vector2.hpp"
#include "entities/entity.hpp"


namespace engine {


class Tex2d : public Entity {
	public:
		Tex2d();
		Tex2d(SDL_Texture*, float, float, float = 1.0f, float = 1.0f);
		void Render(SDL_Renderer*);
		SDL_Rect TextureRect(SDL_Texture*);
		SDL_Texture* texture;
		SDL_Rect texture_rect;
		Transform2d transform;
		Vector2 offset;
};


}	// namespace engine
