#pragma once


// Local library includes
#include "imgui.h"


namespace utils {


class Utils {
	public:
		static char* CppStandard();
		static void ImGuiTextCentered(const char*);
		static void ImGuiTextColoredCentered(const ImColor, const char*);
		static int SignOfInt(int value);
		static float SignOfFloat(float value);
};


}	// namespace utils
