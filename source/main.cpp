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
#include "utils/colors.hpp"
#include "utils/fonts.hpp"
#include "utils/framerate.hpp"


// Controller assets
#include "signature_white_png.h"
#include "debug_controller_outline_png.h"
#include "debug_controller_button_start_png.h"
#include "debug_controller_button_a_png.h"
#include "debug_controller_button_b_png.h"
#include "debug_controller_button_x_png.h"
#include "debug_controller_button_y_png.h"
#include "debug_controller_trigger_l_png.h"
#include "debug_controller_trigger_r_png.h"
#include "debug_controller_trigger_z_png.h"
#include "debug_controller_direction_up_png.h"
#include "debug_controller_direction_down_png.h"
#include "debug_controller_direction_left_png.h"
#include "debug_controller_direction_right_png.h"
#include "debug_controller_stick_left_png.h"
#include "debug_controller_stick_right_png.h"


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

	f32 stick_left_x_position = 17;
	f32 stick_left_y_position = 94;
	f32 stick_left_x_offset = 0;
	f32 stick_left_y_offset = 0;
	f32 stick_right_x_position = 154;
	f32 stick_right_y_position = 163;
	f32 stick_right_x_offset = 0;
	f32 stick_right_y_offset = 0;
	GRRLIB_texImg *signature_white = GRRLIB_LoadTexture(signature_white_png);
	GRRLIB_texImg *debug_controller_outline = GRRLIB_LoadTexture(debug_controller_outline_png);
	GRRLIB_texImg *debug_controller_button_start = GRRLIB_LoadTexture(debug_controller_button_start_png);
	GRRLIB_texImg *debug_controller_button_a = GRRLIB_LoadTexture(debug_controller_button_a_png);
	GRRLIB_texImg *debug_controller_button_b = GRRLIB_LoadTexture(debug_controller_button_b_png);
	GRRLIB_texImg *debug_controller_button_x = GRRLIB_LoadTexture(debug_controller_button_x_png);
	GRRLIB_texImg *debug_controller_button_y = GRRLIB_LoadTexture(debug_controller_button_y_png);
	GRRLIB_texImg *debug_controller_trigger_l = GRRLIB_LoadTexture(debug_controller_trigger_l_png);
	GRRLIB_texImg *debug_controller_trigger_r = GRRLIB_LoadTexture(debug_controller_trigger_r_png);
	GRRLIB_texImg *debug_controller_trigger_z = GRRLIB_LoadTexture(debug_controller_trigger_z_png);
	GRRLIB_texImg *debug_controller_direction_up = GRRLIB_LoadTexture(debug_controller_direction_up_png);
	GRRLIB_texImg *debug_controller_direction_down = GRRLIB_LoadTexture(debug_controller_direction_down_png);
	GRRLIB_texImg *debug_controller_direction_left = GRRLIB_LoadTexture(debug_controller_direction_left_png);
	GRRLIB_texImg *debug_controller_direction_right = GRRLIB_LoadTexture(debug_controller_direction_right_png);
	GRRLIB_texImg *debug_controller_stick_left = GRRLIB_LoadTexture(debug_controller_stick_left_png);
	GRRLIB_texImg *debug_controller_stick_right = GRRLIB_LoadTexture(debug_controller_stick_right_png);

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
		if (buttonsDown0 & PAD_TRIGGER_Z) {
			framerate.ToggleShowHide();
		}

		if (stick_left_x > deadzone_stick_left
		|| stick_left_x < -deadzone_stick_left) {
			stick_left_x_offset = stick_left_x / 10.0;
		} else {
			stick_left_x_offset = 0;
		}

		if (stick_left_y > deadzone_stick_left
		|| stick_left_y < -deadzone_stick_left) {
			stick_left_y_offset = -stick_left_y / 10.0;
		} else {
			stick_left_y_offset = 0;
		}

		if (stick_right_x > deadzone_stick_right
		|| stick_right_x < -deadzone_stick_right) {
			stick_right_x_offset = stick_right_x / 10.0;
		} else {
			stick_right_x_offset = 0;
		}

		if (stick_right_y > deadzone_stick_right
		|| stick_right_y < -deadzone_stick_right) {
			stick_right_y_offset = -stick_right_y / 10.0;
		} else {
			stick_right_y_offset = 0;
		}


		grr_state.Use2dMode();
		GRRLIB_DrawImg(0, 0, debug_controller_outline, 0, 1, 1, GRRLIB_WHITE);
		GRRLIB_DrawImg(86, 66, signature_white, 0, 0.7, 0.7, GRRLIB_WHITE);
		GRRLIB_DrawImg(
			stick_left_x_position + stick_left_x_offset,
			stick_left_y_position + stick_left_y_offset,
			debug_controller_stick_left, 0, 1, 1, GRRLIB_WHITE
		);
		GRRLIB_DrawImg(
			stick_right_x_position + stick_right_x_offset,
			stick_right_y_position + stick_right_y_offset,
			debug_controller_stick_right, 0, 1, 1, GRRLIB_WHITE
		);
		if (buttonsHeld0 & PAD_BUTTON_START) {
			GRRLIB_DrawImg(121, 114, debug_controller_button_start, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_A) {
			GRRLIB_DrawImg(192, 108, debug_controller_button_a, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_B) {
			GRRLIB_DrawImg(170, 131, debug_controller_button_b, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_X) {
			GRRLIB_DrawImg(220, 102, debug_controller_button_x, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_Y) {
			GRRLIB_DrawImg(185, 83, debug_controller_button_y, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_TRIGGER_L) {
			GRRLIB_DrawImg(13, 39, debug_controller_trigger_l, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_TRIGGER_R) {
			GRRLIB_DrawImg(182, 37, debug_controller_trigger_r, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_TRIGGER_Z) {
			GRRLIB_DrawImg(182, 42, debug_controller_trigger_z, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_UP) {
			GRRLIB_DrawImg(78, 158, debug_controller_direction_up, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_DOWN) {
			GRRLIB_DrawImg(78, 182, debug_controller_direction_down, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_LEFT) {
			GRRLIB_DrawImg(67, 171, debug_controller_direction_left, 0, 1, 1, GRRLIB_WHITE);
		}
		if (buttonsHeld0 & PAD_BUTTON_RIGHT) {
			GRRLIB_DrawImg(89, 171, debug_controller_direction_right, 0, 1, 1, GRRLIB_WHITE);
		}


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
