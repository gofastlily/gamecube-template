#include "utils/framerate.hpp"


// Linked library includes
#include <ogc/lwp_watchdog.h>  // Needed for gettime and ticks_to_millisecs


// Local library includes
#include "imgui.h"


#define ONE_SECOND_IN_MILLISECONDS 1000


namespace game {


namespace utils {


const char *FPS_STRING = "Current FPS: %d";


Framerate::Framerate(bool show) {
	m_show = show;
}


/**
 * This function calculates the number of frames we render each second.
 * 
 * Borrowed from GRRLIB's GameCube Examples.
 * https://github.com/GRRLIB/GRRLIB/blob/v4.5.1/examples/gamecube/basic_drawing/source/main.c#L215-L232
 * 
 * License: licences/GRRLIB.txt
 * 
 * @return The number of frames per second.
 */
void Framerate::Calculate() {
	static u8 frameCount = 0;
	static u32 lastTime;
	static u8 FPS = 0;
	const u32 currentTime = ticks_to_millisecs(gettime());

	frameCount++;
	if(currentTime - lastTime > ONE_SECOND_IN_MILLISECONDS) {
		lastTime = currentTime;
		FPS = frameCount;
		frameCount = 0;
	}
	m_framerate = FPS;
}


void Framerate::Display() {
	if (m_show) {
		ImGui::SetNextWindowPos(ImVec2(x_position, y_position));
		ImGui::SetNextWindowSize(ImVec2(m_width, m_height));
		ImGui::Begin(
			"Framerate: 00", nullptr,
			ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoNav
		);
		ImGui::Text(FPS_STRING, m_framerate);
		ImGui::End();
	}
}


void Framerate::ToggleShowHide() {
	m_show = !m_show;
}


}	// namespace utils


}	// namespace game
