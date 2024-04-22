#include "utils/fonts.hpp"


// Library includes
#include <grrlib.h>


namespace game {


Fonts::Fonts() {
	// Configure the fonts
	grrlib_font_5 = GRRLIB_LoadTexture(grrlib_font_5_png);
	// TODO: Move values to config
	GRRLIB_InitTileSet(grrlib_font_5, 8, 16, 0);
}


}
