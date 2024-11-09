#include "gamepad.hpp"


// Local library includes
#include "imgui.h"


namespace input {


Gamepad::Gamepad() {
	stick_left.x.minimum_limit = -78.5f;
	stick_left.y.minimum_limit = -78.5f;
	stick_left.x.maximum_limit = 78.5f;
	stick_left.y.maximum_limit = 78.5f;
	stick_right.x.minimum_limit = -71.5f;
	stick_right.y.minimum_limit = -71.5f;
	stick_right.x.maximum_limit = 71.5f;
	stick_right.y.maximum_limit = 71.5f;
	trigger_left.minimum_limit = 50.0f;
	trigger_right.minimum_limit = 50.0f;
	trigger_left.maximum_limit = 99.0f;
	trigger_right.maximum_limit = 99.0f;
}


void Gamepad::ProcessInput(SDL_Event& event) {
	if (!IsConnected()) return;
	if (!CheckEventMatchesController(event)) return;

	switch (event.type) {
		case SDL_CONTROLLERBUTTONDOWN:
		case SDL_CONTROLLERBUTTONUP:
			ProcessButtonInput(event);
			break;
		case SDL_CONTROLLERAXISMOTION:
			ProcessAxisInput(event);
			break;
	}
}


void Gamepad::ProcessAxisInput(SDL_Event& event) {
	switch (event.cbutton.button) {
		case SDL_CONTROLLER_AXIS_LEFTX:
		case SDL_CONTROLLER_AXIS_LEFTY:
			stick_left.ProcessInput(event);
			break;
		case SDL_CONTROLLER_AXIS_RIGHTX:
		case SDL_CONTROLLER_AXIS_RIGHTY:
			stick_right.ProcessInput(event);
			break;
		case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
			trigger_left.ProcessInput(event);
			break;
		case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
			trigger_right.ProcessInput(event);
			break;
	}
}


void Gamepad::ProcessButtonInput(SDL_Event& event) {
	switch (event.cbutton.button) {
		case GCN_CONTROLLER_BUTTON_START:
			button_start.ProcessInput(event);
			break;
		case GCN_CONTROLLER_BUTTON_A:
			button_a.ProcessInput(event);
			break;
		case GCN_CONTROLLER_BUTTON_B:
			button_b.ProcessInput(event);
			break;
		case GCN_CONTROLLER_BUTTON_L:
			button_l.ProcessInput(event);
			break;
		case GCN_CONTROLLER_BUTTON_R:
			button_r.ProcessInput(event);
			break;
		case GCN_CONTROLLER_BUTTON_X:
			button_x.ProcessInput(event);
			break;
		case GCN_CONTROLLER_BUTTON_Y:
			button_y.ProcessInput(event);
			break;
		case GCN_CONTROLLER_BUTTON_Z:
			button_z.ProcessInput(event);
			break;
		case GCN_CONTROLLER_DPAD_UP:
			dpad_up.ProcessInput(event);
			break;
		case GCN_CONTROLLER_DPAD_DOWN:
			dpad_down.ProcessInput(event);
			break;
		case GCN_CONTROLLER_DPAD_LEFT:
			dpad_left.ProcessInput(event);
			break;
		case GCN_CONTROLLER_DPAD_RIGHT:
			dpad_right.ProcessInput(event);
			break;
	}
}


int Gamepad::InstanceID() {
	return SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(controller));
}


bool Gamepad::CheckEventMatchesController(SDL_Event& event) {
	return (event.cdevice.which == InstanceID());
}


void Gamepad::Connect(SDL_GameController* _controller) {
	controller = _controller;
}


void Gamepad::Disconnect() {
	SDL_GameControllerClose(controller);
	controller = nullptr;
}


bool Gamepad::IsConnected() {
	if (!controller) {
		return false;
	}
	return SDL_GameControllerGetAttached(controller);
}


void Gamepad::ResetAxisStates() {
	stick_left.ResetState();
	stick_right.ResetState();
}


void Gamepad::ResetButtonStates() {
	button_start.ResetState();
	button_z.ResetState();
	button_start.ResetState();
	button_a.ResetState();
	button_b.ResetState();
	button_l.ResetState();
	button_r.ResetState();
	button_x.ResetState();
	button_y.ResetState();
	button_z.ResetState();
	dpad_up.ResetState();
	dpad_down.ResetState();
	dpad_left.ResetState();
	dpad_right.ResetState();
}


}	// namespace input
