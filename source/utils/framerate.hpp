#pragma once


#define FRAMERATE_DEFAULT_VISIBILITY true


namespace utils {


class Framerate {
	public:
		Framerate(bool=FRAMERATE_DEFAULT_VISIBILITY);
		void Calculate();
		void Display();
		void ToggleShowHide();
		int framerate;
		bool show;
		int width = 125;
		int height = 25;
		float x_position = 500.0f;
		float y_position = 10.0f;
};


}	// namespace utils
