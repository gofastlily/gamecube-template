#pragma once


namespace engine {


struct Vector2 {
	Vector2() {};
	Vector2(float x, float y) : x(x), y(y) {};
	float x = 0.0f;
	float y = 0.0f;
};


}	// namespace engine
