#pragma once


namespace utils {


class Timer {
	public:
		Timer(bool=false, bool=false, int=0, int=0);
		void Start();
		void Stop();
		void Pause();
		void Unpause();
		int Ticks();
		bool IsStarted();
		bool IsPaused();
		bool is_started;
		bool is_paused;
		int base_ticks;
		int ticks_at_pause;
};


}	// namespace utils
