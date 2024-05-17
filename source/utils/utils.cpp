#include "utils.hpp"


// Local library includes
#include "imgui.h"


namespace utils {


char* Utils::CppStandard() {
	switch (__cplusplus) {
		case 202101L: return (char*)"C++23";
		case 202002L: return (char*)"C++20";
		case 201703L: return (char*)"C++17";
		case 201402L: return (char*)"C++14";
		case 201103L: return (char*)"C++11";
		case 199711L: return (char*)"C++98";
		default: return (char*)"pre-standard C++";
	}
}


void Utils::ImGuiTextCentered(const char* text) {
	float window_width = ImGui::GetWindowSize().x;
	float text_width = ImGui::CalcTextSize(text).x;

	ImGui::SetCursorPosX((window_width - text_width) * 0.5f);
	ImGui::Text(text);
}


void Utils::ImGuiTextColoredCentered(const ImColor color, const char* text) {
	float window_width = ImGui::GetWindowSize().x;
	float text_width = ImGui::CalcTextSize(text).x;

	ImGui::SetCursorPosX((window_width - text_width) * 0.5f);
	ImGui::TextColored(color, text);
}


int Utils::SignOfInt(int value) {
    return (0 < value) - (value < 0);
}


float Utils::SignOfFloat(float value) {
    return (0.0f < value) - (value < 0.0f);
}


}	// namespace utils
