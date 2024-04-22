#ifndef UTILS_GRRSTATE_HPP
#define UTILS_GRRSTATE_HPP 1


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


#endif  // UTILS_GRRSTATE_HPP
