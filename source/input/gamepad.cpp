#include "input/gamepad.hpp"


// Local library includes
#include "imgui.h"


namespace input {


Gamepad::Gamepad() { }


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
			stick_left_x = AxisValueWithDeadzone(event.caxis.value);
			break;
		case SDL_CONTROLLER_AXIS_RIGHTX:
			stick_right_x = AxisValueWithDeadzone(event.caxis.value);
			break;
		case SDL_CONTROLLER_AXIS_LEFTY:
			stick_left_y = AxisValueWithDeadzone(event.caxis.value);
			break;
		case SDL_CONTROLLER_AXIS_RIGHTY:
			stick_right_y = AxisValueWithDeadzone(event.caxis.value);
			break;
		case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
			trigger_left = AxisValueWithDeadzone(event.caxis.value);
			break;
		case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
			trigger_right = AxisValueWithDeadzone(event.caxis.value);
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


float Gamepad::AxisValueWithDeadzone(float value) {
	if (value > deadzone || value < -deadzone) {
		return value / SDL_JOYSTICK_AXIS_MAX * 100.0f;
	}
	return 0.0f;
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
	return SDL_GameControllerGetAttached(controller);
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
