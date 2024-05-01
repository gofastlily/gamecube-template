#pragma once


// Local source includes
#include "engine/id.hpp"


namespace engine {


struct Entity {
	int id = Id::Instance().NextUniqueId();
};


}	// namespace engine
