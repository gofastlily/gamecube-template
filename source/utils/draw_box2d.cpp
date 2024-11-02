#include "draw_box2d.hpp"


// Standard library includes
#include <vector>


namespace utils {


DrawBox2d::DrawBox2d() {}


void DrawBox2d::DrawPolygon(const b2Vec2* verticies, int32 vertex_count, const b2Color& color) {
	// convert the Box2D color to an SDL2 color
	SDL_Color color_outline = Box2dColorToSDLColor(color);

	// Render the outline of the polygon
	SDL_SetRenderDrawColor(renderer, color_outline.r, color_outline.g, color_outline.b, color_outline.a);
	for (int i = 0; i < vertex_count; ++i) {
		const b2Vec2 line_start = MeterToPixel(verticies[i]);
		const b2Vec2 line_end = MeterToPixel(verticies[((i < (vertex_count - 1)) ? (i + 1) : 0)]);
		SDL_RenderDrawLineF(renderer, line_start.x, line_start.y, line_end.x, line_end.y);
	}
}

void DrawBox2d::DrawSolidPolygon(const b2Vec2* verticies, int32 vertex_count, const b2Color& color) {
	// convert the Box2D color to an SDL2 color
	SDL_Color color_outline = Box2dColorToSDLColor(color);
	SDL_Color color_fill = Box2dColorToSDLColor(b2Color(
		color.r * 0.5,
		color.g * 0.5,
		color.b * 0.5,
		color.a * 0.5
	));

	// Prepare the SDL vertices
	std::vector<SDL_Vertex> sdl_vertices;

	// loop through the incoming verticies and and adjust with render scaling factor
	for (int i = 0; i < vertex_count; ++i) {
		if (i < (vertex_count - 2)) {
			const b2Vec2 triangle_vertex[3] = {
				MeterToPixel(verticies[0 + 0]),
				MeterToPixel(verticies[0 + 0]),
				MeterToPixel(verticies[0 + 0])
			};

			for (int j = 0; j < 3; ++j) {
				sdl_vertices.push_back({
					{triangle_vertex[j].x, triangle_vertex[j].y},
					color_fill,
					{0.0f, 0.0f}
				});
			}
		}
	}

	// Render the polygon
	SDL_RenderGeometry(renderer, nullptr, sdl_vertices.data(), sdl_vertices.size(), nullptr, 0);

	// Render the outline of the polygon
	SDL_SetRenderDrawColor(renderer, color_outline.r, color_outline.g, color_outline.b, color_outline.a);
	for (int i = 0; i < vertex_count; ++i) {
		const b2Vec2 line_start = MeterToPixel(verticies[i]);
		const b2Vec2 line_end = MeterToPixel(verticies[((i < (vertex_count - 1)) ? (i + 1) : 0)]);
		SDL_RenderDrawLineF(renderer, line_start.x, line_start.y, line_end.x, line_end.y);
	}
}

void DrawBox2d::DrawCircle(const b2Vec2& center, float radius, const b2Color& color) {
	return;
}

void DrawBox2d::DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color) {
	return;
}

void DrawBox2d::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
	return;
}

void DrawBox2d::DrawTransform(const b2Transform& transform) {
	return;
}

void DrawBox2d::DrawPoint(const b2Vec2& p, float size, const b2Color& color) {
	return;
}


SDL_Color DrawBox2d::Box2dColorToSDLColor(const b2Color& box2d_color) {
	return {
		(uint8)(box2d_color.r * 255.0f),
		(uint8)(box2d_color.g * 255.0f),
		(uint8)(box2d_color.b * 255.0f),
		(uint8)(box2d_color.a * 255.0f)
	};
}


int DrawBox2d::MeterToPixel(const float meters) {
	return meters * pixels_per_meter;
}


b2Vec2 DrawBox2d::MeterToPixel(const b2Vec2& meters_vector) {
	return b2Vec2(
		MeterToPixel(meters_vector.x),
		MeterToPixel(meters_vector.y)
	);
}


float DrawBox2d::PixelToMeter(const int pixels) {
	return pixels / pixels_per_meter;
}


}	// namespace utils
