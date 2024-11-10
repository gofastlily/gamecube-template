#pragma once


// Local library includes
#include "imgui.h"


// Local source includes
#include "vector2.hpp"


namespace utils {


class Utils {
	public:
		static char* CppStandard();
		static void ImGuiTextCentered(const char*);
		static void ImGuiTextColoredCentered(const ImColor, const char*);
		static int SignOfInt(int value);
		static float SignOfFloat(float value);
		static engine::Vector2 PointOnCircle(float, float);
};


}	// namespace utils
