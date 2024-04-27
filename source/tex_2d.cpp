#include "tex_2d.hpp"


// Local library includes
#include "imgui.h"


Tex2d::Tex2d() { }


Tex2d::Tex2d(SDL_Texture *_texture, float _x_position, float _y_position, float _x_scale, float _y_scale) : texture(nullptr) {
	texture = _texture;
	x_position = _x_position;
	y_position = _y_position;
	x_scale = _x_scale;
	y_scale = _y_scale;
}


void Tex2d::Render(SDL_Renderer *renderer) {
    texture_rect = TextureRect(texture, x_position, y_position, x_scale, y_scale);
	SDL_RenderCopy(renderer, texture, NULL, &texture_rect);
}


SDL_Rect Tex2d::TextureRect(SDL_Texture* texture, float x_position, float y_position, float x_scale, float y_scale) {
	// Query the height and width of the texture
	int texture_width;
	int texture_height;
	SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);

	// Build the required rect using the height and width
	SDL_Rect rect;
	rect.x = x_position;
	rect.y = y_position;
	rect.w = texture_width * x_scale;
	rect.h = texture_height * y_scale;
	return rect;
}
