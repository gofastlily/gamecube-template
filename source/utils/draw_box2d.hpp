#pragma once


// Linked library includes
#include <SDL2/SDL.h>


// Local library includes
#include "box2d.h"


namespace utils {


class DrawBox2d : public b2Draw {
	public:
		DrawBox2d();
		SDL_Renderer* renderer;
		void DrawPolygon(const b2Vec2*, int32, const b2Color&) override;
		void DrawSolidPolygon(const b2Vec2*, int32, const b2Color&) override;
		void DrawCircle(const b2Vec2&, float, const b2Color&) override;
		void DrawSolidCircle(const b2Vec2&, float, const b2Vec2&, const b2Color&) override;
		void DrawSegment(const b2Vec2&, const b2Vec2&, const b2Color&) override;
		void DrawTransform(const b2Transform&) override;
		void DrawPoint(const b2Vec2&, float, const b2Color&) override;
};


}	// namespace utils
