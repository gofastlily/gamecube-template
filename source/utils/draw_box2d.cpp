#include "draw_box2d.hpp"


// Standard library includes
#include <vector>


namespace utils {


DrawBox2d::DrawBox2d() {}


void DrawBox2d::DrawPolygon(const b2Vec2* verticies, int32 vertex_count, const b2Color& color) {
	return;
}

void DrawBox2d::DrawSolidPolygon(const b2Vec2* verticies, int32 vertex_count, const b2Color& color) {
	return;
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


}	// namespace utils
