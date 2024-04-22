#pragma once


// Library includes
#include <grrlib.h>


// Local includes
#include "grrstate.hpp"
#include "utils/colors.hpp"


#define FRAMERATE_DEFAULT_VISIBILITY true


namespace game {


class Framerate {
	public:
		Framerate(GRRState&, GRRLIB_texImg*, unsigned int=GRRLIB_WHITE, bool=FRAMERATE_DEFAULT_VISIBILITY);
		void Calculate();
		void Display();
		void ToggleShowHide();
		f32 x_position = 500.0f;
		f32 y_position = 27.0f;
	private:
		unsigned int m_color;
		GRRLIB_texImg* m_font;
		u8 m_framerate;
		bool m_show;
		GRRState m_grr_state;
};


}  // namespace game
