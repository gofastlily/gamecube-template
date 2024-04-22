#pragma once


// Library includes
#include <grrlib.h>


/**
 * This font was borrowed from GRRLIB's GameCube Examples.
 * https://github.com/GRRLIB/GRRLIB/tree/v4.5.1/examples/gamecube/basic_drawing/data/BMfont5.png
 * 
 * License: licences/GRRLIB.txt
 */
#include "grrlib_font_5_png.h"


namespace game {


class Fonts {
    public:
        Fonts();
        GRRLIB_texImg* grrlib_font_5;
};


}
