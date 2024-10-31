#include "text.hpp"
#include "text.hpp"


namespace engine {


Text::Text() {};


Text::Text(SDL_Renderer* renderer, std::string text, TTF_Font* font, SDL_Color color, int wrap_width)
: renderer(renderer), value(text), font(font), color(color), wrap_width(wrap_width) {
	CreateSurface();
	CreateTexture();
}


void Text::CreateSurface() {
	surface = TTF_RenderText_Blended_Wrapped(font, value.c_str(), color, wrap_width);
}


void Text::CreateTexture() {
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}


void Text::Render() {
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
}


void Text::Render(SDL_Rect* crop) {
	SDL_RenderCopy(renderer, texture, crop, &rect);
}

void Text::UpdateText(std::string text) {
	value = text;
	CreateSurface();
	CreateTexture();
}

} // namespace engine
