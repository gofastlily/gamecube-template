#include "debug_controllers/manager.hpp"


namespace utils {


namespace debug_controllers {


Manager::Manager(bool show) {
	for (int i = 0; i < CONTROLLER_COUNT; i++) {
		debug_controllers[i] = DebugController(show);
	}
};


void Manager::Init(SDL_Renderer* renderer) {
	for (int i = 0; i < CONTROLLER_COUNT; i++) {
		debug_controllers[i].Init(renderer, i);
	}
}


void Manager::Update(input::Input& input) {
	for (int i = 0; i < CONTROLLER_COUNT; i++) {
		debug_controllers[i].Update(input.gamepads[i]);
	}
	if (input.gamepads[0].button_l.held && input.gamepads[0].dpad_down.pressed) {
		ToggleShowHide();
	}
}


void Manager::Render(SDL_Renderer* renderer) {
	for (int i = 0; i < CONTROLLER_COUNT; i++) {
		debug_controllers[i].Render(renderer);
	}
}


void Manager::ToggleShowHide() {
	for (int i = 0; i < CONTROLLER_COUNT; i++) {
		debug_controllers[i].ToggleShowHide();
	}
}


}	// namespace debug_controllers


}	// namespace utils
