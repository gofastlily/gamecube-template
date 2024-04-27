#pragma once


// Linked library includes
#include <SDL2/SDL.h>


class Tex2d {
	public:
		Tex2d();
		Tex2d(SDL_Texture*, float, float, float = 1.0f, float = 1.0f);
		SDL_Texture* texture;
		SDL_Rect texture_rect;
		float x_position;
		float y_position;
		float x_scale;
		float y_scale;
		void Render(SDL_Renderer*);
		static SDL_Rect TextureRect(SDL_Texture*, float, float, float = 1.0f, float = 1.0f);
};
