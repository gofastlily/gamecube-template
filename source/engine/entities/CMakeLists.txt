add_library(Entities
	game_object.cpp
)

target_include_directories(Entities INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(Entities PUBLIC
	compiler_flags
	SDL2::SDL2
	Constants
	Engine
)
