#pragma once


// Standard library includes
#include <memory>


namespace engine {


class Id {
	private:
		Id() {}
	public:
		static Id& Instance() {
			static Id instance;
			return instance;
		}
		int NextUniqueId() {
			return next_id++;
		}
		int next_id = 1;
};


}	// namespace engine
