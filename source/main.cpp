/***
 * Gamecube Template
 */


// Library includes
// #define DEBUG true
#ifdef DEBUG
#include <debug.h>
#endif

#include <grrlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <ogc/pad.h>


// Local includes
#include "grrstate.hpp"
#include "utils/debug_controller.hpp"
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
	game::DebugController debug_controller = game::DebugController(true);

	int deadzone = 3;
	int deadzone_stick_left = deadzone;
	int deadzone_stick_right = deadzone;


	///////////////
	// Game Loop //
	///////////////
	while(1) {
		///////////////////
		// Process Input //
		///////////////////
		PAD_ScanPads();	// Scan the GameCube controllers
		u16 buttonsDown0 = PAD_ButtonsDown(0);
		u16 buttonsHeld0 = PAD_ButtonsHeld(0);
		s8 stick_left_x = PAD_StickX(PAD_CHAN0);
		s8 stick_left_y = PAD_StickY(PAD_CHAN0);
		s8 stick_right_x = PAD_SubStickX(PAD_CHAN0);
		s8 stick_right_y = PAD_SubStickY(PAD_CHAN0);


		//////////////////
		// Update State //
		//////////////////
		if (buttonsHeld0 & PAD_TRIGGER_L && buttonsDown0 & PAD_BUTTON_DOWN) {
			debug_controller.ToggleShowHide();
			framerate.ToggleShowHide();
		}

		if (stick_left_x > deadzone_stick_left
		|| stick_left_x < -deadzone_stick_left) {
			debug_controller.stick_left_x_offset = stick_left_x / 10.0;
		} else {
			debug_controller.stick_left_x_offset = 0;
		}

		if (stick_left_y > deadzone_stick_left
		|| stick_left_y < -deadzone_stick_left) {
			debug_controller.stick_left_y_offset = -stick_left_y / 10.0;
		} else {
			debug_controller.stick_left_y_offset = 0;
		}

		if (stick_right_x > deadzone_stick_right
		|| stick_right_x < -deadzone_stick_right) {
			debug_controller.stick_right_x_offset = stick_right_x / 10.0;
		} else {
			debug_controller.stick_right_x_offset = 0;
		}

		if (stick_right_y > deadzone_stick_right
		|| stick_right_y < -deadzone_stick_right) {
			debug_controller.stick_right_y_offset = -stick_right_y / 10.0;
		} else {
			debug_controller.stick_right_y_offset = 0;
		}

		grr_state.Use2dMode();
		debug_controller.Display();
		framerate.Display();


		//////////////////
		// Render State //
		//////////////////
		GRRLIB_Render();	// Render the frame buffer to the TV
		framerate.Calculate();
	}

	GRRLIB_Exit();	// Be a good girl, clear the memory allocated by GRRLIB

	exit(0);	// Use exit() to exit a program, do not use 'return' from main()
}
