#pragma once


// Local library includes
#include "imgui.h"


#define FRAEMRATE_STATE_HIDDEN	0
#define FRAMERATE_STATE_MINIMAL	1
#define FRAMERATE_STATE_FULL	2
#define FRAMERATE_STATE_COUNT	3
#define FRAMERATE_DEFAULT_STATE FRAMERATE_STATE_MINIMAL


namespace utils {


class Framerate {
	public:
		Framerate(ImGuiIO&, int=FRAMERATE_DEFAULT_STATE);
		void Calculate();
		void Display();
		void IncrementState();
		int framerate;
		ImGuiIO& io;
		bool show;
		int state;
		int width = 145;
		int height = 25;
		float x_position = 480.0f;
		float y_position = 15.0f;
};


}	// namespace utils
