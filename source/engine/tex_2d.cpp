#include "tex_2d.hpp"


namespace engine {


Tex2d::Tex2d() { }


Tex2d::Tex2d(SDL_Texture *_texture, float x_position, float y_position, float x_scale, float y_scale) : texture(nullptr) {
	texture = _texture;
	transform.position.x = x_position;
	transform.position.y = y_position;
	transform.scale.x = x_scale;
	transform.scale.y = y_scale;
}


void Tex2d::Render(SDL_Renderer *renderer) {
    texture_rect = TextureRect(texture);
	SDL_RenderCopyEx(renderer, texture, nullptr, &texture_rect, transform.rotation, nullptr, SDL_FLIP_NONE);
}


SDL_Rect Tex2d::TextureRect(SDL_Texture* texture) {
	// Query the height and width of the texture
	int texture_width;
	int texture_height;
	SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);

	// Build the required rect using the height and width
	SDL_Rect rect;
	rect.x = transform.position.x + offset.x;
	rect.y = transform.position.y + offset.y;
	rect.w = texture_width * transform.scale.x;
	rect.h = texture_height * transform.scale.y;
	return rect;
}


}	// namespace engine
