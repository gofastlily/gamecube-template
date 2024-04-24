#pragma once


#define FRAMERATE_DEFAULT_VISIBILITY true


namespace game {


namespace utils {


class Framerate {
	public:
		Framerate(bool=FRAMERATE_DEFAULT_VISIBILITY);
		void Calculate();
		void Display();
		void ToggleShowHide();
		float x_position = 500.0f;
		float y_position = 10.0f;
	private:
		int m_framerate;
		bool m_show;
		int m_width = 125;
		int m_height = 25;
};


}	// namespace utils


}	// namespace game
