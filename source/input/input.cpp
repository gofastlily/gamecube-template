#include "input/input.hpp"


namespace input {


Input::Input() {
	ConnectAllControllers();
}


void Input::ProcessInputs() {
	ResetButtonStateForAllControllers();
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0) {
		ProcessInput(event);
	}
}


void Input::ProcessInput(SDL_Event& event) {
	switch (event.type) {
		case SDL_CONTROLLERDEVICEADDED:
			ProcessControllerConnected(event);
			break;
		case SDL_CONTROLLERDEVICEREMOVED:
			ProcessControllerDisconnected(event);
			break;
		case SDL_CONTROLLERBUTTONDOWN:
		case SDL_CONTROLLERBUTTONUP:
		case SDL_CONTROLLERAXISMOTION:
			gamepads[0].ProcessInput(event);
			gamepads[1].ProcessInput(event);
			gamepads[2].ProcessInput(event);
			gamepads[3].ProcessInput(event);
			break;
	}
}


void Input::ProcessControllerConnected(SDL_Event& event) {
	if (!gamepads[0].IsConnected()) {
		gamepads[0].Connect(SDL_GameControllerOpen(event.cdevice.which));
	} else if (!gamepads[1].IsConnected()) {
		gamepads[1].Connect(SDL_GameControllerOpen(event.cdevice.which));
	} else if (!gamepads[2].IsConnected()) {
		gamepads[2].Connect(SDL_GameControllerOpen(event.cdevice.which));
	} else if (!gamepads[3].IsConnected()) {
		gamepads[3].Connect(SDL_GameControllerOpen(event.cdevice.which));
	}
}


void Input::ProcessControllerDisconnected(SDL_Event& event) {
	if (gamepads[0].CheckEventMatchesController(event)) gamepads[0].Disconnect();
	if (gamepads[1].CheckEventMatchesController(event)) gamepads[1].Disconnect();
	if (gamepads[1].CheckEventMatchesController(event)) gamepads[1].Disconnect();
	if (gamepads[1].CheckEventMatchesController(event)) gamepads[1].Disconnect();
}


SDL_GameController *Input::FindNextController() {
	int num_joysticks = SDL_NumJoysticks();
	for (int i = 0; i < num_joysticks; i++) {
		if (gamepads[i].IsConnected()) continue;
		if (!SDL_IsGameController(i)) continue;
		return SDL_GameControllerOpen(i);
	}
	return nullptr;
}


void Input::ConnectAllControllers() {
	for (int i = 0; i < CONTROLLER_COUNT; i++) {
		gamepads[i].Connect(FindNextController());
	}
}


void Input::ResetButtonStateForAllControllers() {
	for (int i = 0; i < CONTROLLER_COUNT; i++) {
		if (!gamepads[i].IsConnected()) continue;
		gamepads[i].ResetButtonStates();
	}
}


}	// namespace input
