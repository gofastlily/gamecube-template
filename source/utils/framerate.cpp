#include "utils/framerate.hpp"


// Linked library includes
#include <ogc/lwp_watchdog.h>	// Needed for gettime and ticks_to_millisecs


// Local library includes
#include "imgui.h"


#define ONE_SECOND_IN_MILLISECONDS 1000


namespace utils {


const char *FPS_STRING = "Current FPS: %.2f";
const char *FRAME_TIME_STRING = "Avg. FT %.3f ms (%.2f FPS)";
const char *VERTICES_STRING = "%d vert, %d ind (%d tri)";


Framerate::Framerate(ImGuiIO& _io, int _state) : io(_io), state(_state) { }


void Framerate::Display() {
	if (!state) return;

	ImGui::SetNextWindowPos(ImVec2(x_position - (100 * (state - 1)), y_position));
	ImGui::SetNextWindowSize(ImVec2(width * state, height * state));
	ImGui::Begin(
		"Framerate", nullptr,
		ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground \
		| ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoFocusOnAppearing
	);

	switch (state) {
		case 1:
			ImGui::Text(FPS_STRING, io.Framerate);
			break;
		case 2:
			ImGui::Text(FRAME_TIME_STRING, 1000.0f / io.Framerate, io.Framerate);
			ImGui::Text(VERTICES_STRING, io.MetricsRenderVertices, io.MetricsRenderIndices, io.MetricsRenderIndices / 3);
			break;
	}

	ImGui::End();
}


void Framerate::IncrementState() {
	state++;
	if (state >= FRAMERATE_STATE_COUNT) state = FRAEMRATE_STATE_HIDDEN;
}


}	// namespace utils
