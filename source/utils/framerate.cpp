#include "utils/framerate.hpp"


// Library includes
#include <ogc/lwp_watchdog.h>  // Needed for gettime and ticks_to_millisecs


// Local includes
#include "grrstate.hpp"


namespace game {


const char *FPS_STRING = "Current FPS: %d";


Framerate::Framerate(GRRState& grr_state, GRRLIB_texImg* font, unsigned int color, bool show) {
	m_font = font;
	m_color = color;
	m_show = show;
	m_grr_state = grr_state;
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
	if(currentTime - lastTime > 1000) {
		lastTime = currentTime;
		FPS = frameCount;
		frameCount = 0;
	}
	m_framerate = FPS;
}


void Framerate::Display() {
	if (m_show) {
		GRRLIB_Printf(x_position, y_position, m_font, m_color, 1, FPS_STRING, m_framerate);
	}
}


void Framerate::ToggleShowHide() {
	m_show = !m_show;
}


}	// namespace game
