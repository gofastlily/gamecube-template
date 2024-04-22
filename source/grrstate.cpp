#include "grrstate.hpp"


// Library includes
#include <grrlib.h>


namespace game {


GRRState::GRRState() {
	GRRLIB_Init();
	GRRLIB_Settings.antialias = true;
	PAD_Init();	// Initialise the GameCube controllers
	m_3d_mode = true;	// Pre-populate to fill m_previous_3d_mode
	Set3dMode();
}


void GRRState::Use2dMode() {
	m_previous_3d_mode = m_3d_mode;
	m_3d_mode = false;
	Set2dMode();
}


void GRRState::Use3dMode() {
	m_previous_3d_mode = m_3d_mode;
	m_3d_mode = true;
	Set3dMode();
}


void GRRState::UsePreviousMode() {
	bool now_previous_3d_mode = m_3d_mode;
	m_3d_mode = m_previous_3d_mode;
	m_previous_3d_mode = now_previous_3d_mode;
	if (m_3d_mode) {
		Set3dMode();
	} else {
		Set2dMode();
	}
}

void GRRState::Set2dMode() {
	GRRLIB_2dMode();
}

void GRRState::Set3dMode() {
	// TODO: extract to config
	GRRLIB_3dMode(0.1f, 1000.0f, 45.0f, 0, 0);
}


}  // namespace game
