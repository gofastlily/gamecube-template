/***
 * Gamecube Template
 */


// Library includes
// #define DEBUG
#ifdef DEBUG
#include <debug.h>
#endif

#include <grrlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ogc/pad.h>


// Local includes
#include "grrstate.hpp"
#include "utils/fonts.hpp"
#include "utils/framerate.hpp"


int main(int argc, char **argv) {
	#ifdef DEBUG
	/* Configure for use with USB on EXI channel 1 (memcard slot B) */
	/* Other option: GDBSTUB_DEVICE_TCP. Note: second parameter acts as port for this type of device */
	DEBUG_Init(GDBSTUB_DEVICE_USB, 1);

	printf("Waiting for debugger ...\n");
	/* This function call enters the debug stub for the first time */
	/* It's needed to call this if one wants to start debugging. */
	_break();

	printf("debugger connected ...\n");
	#endif

	game::GRRState grr_state = game::GRRState();	// Calls GRRLIB_Init, should be first

	// Pre-loop configuration
	game::Fonts fonts = game::Fonts();
	game::Framerate framerate = game::Framerate(grr_state, fonts.grrlib_font_5);


	///////////////
	// Game Loop //
	///////////////
	while(1) {
		///////////////////
		// Process Input //
		///////////////////
		PAD_ScanPads();	// Scan the GameCube controllers
		u16 buttonsDown0 = PAD_ButtonsDown(0);


		//////////////////
		// Update State //
		//////////////////
		if (buttonsDown0 & PAD_TRIGGER_Z) {
			framerate.ToggleShowHide();
		}


		//////////////////
		// Render State //
		//////////////////
		framerate.Display();
		GRRLIB_Render();	// Render the frame buffer to the TV
		framerate.Calculate();
	}

	GRRLIB_Exit();	// Be a good girl, clear the memory allocated by GRRLIB

	exit(0);	// Use exit() to exit a program, do not use 'return' from main()
}
