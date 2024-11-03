add_library(Input
	axis.cpp
	button.cpp
	gamepad.cpp
	input.cpp
	stick.cpp
)

target_include_directories(Input INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(Input PUBLIC
	compiler_flags
	SDL2::SDL2-static
	Constants
	Entities
	Utils
)
