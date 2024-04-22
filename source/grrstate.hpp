#pragma once


namespace game {


class GRRState {
	public:
		GRRState();
		void Use2dMode();
		void Use3dMode();
		void UsePreviousMode();
	private:
		void Set2dMode();
		void Set3dMode();
		bool m_3d_mode;
		bool m_previous_3d_mode;
};


}  // namespace game
