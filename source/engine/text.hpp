#pragma once


// Standard library includes
#include <string>


// Linked library includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


// Local source includes
#include "entities/entity.hpp"


namespace engine {


class Text : public Entity {
	public:
		Text();
		Text(SDL_Renderer*, std::string, TTF_Font*, SDL_Color, int);
		void CreateSurface();
		void CreateTexture();
		void Render();
		void Render(SDL_Rect*);
		void UpdateText(std::string);
		SDL_Renderer* renderer;
		std::string value;
		TTF_Font* font;
		SDL_Color color;
		int wrap_width;
		SDL_Surface* surface;
		SDL_Texture* texture;
		SDL_Rect rect;
};


}	// namespace engine
