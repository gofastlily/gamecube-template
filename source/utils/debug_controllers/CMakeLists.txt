add_library(DebugControllers
	debug_controller_input.cpp
	debug_controller.cpp
	manager.cpp
)

target_include_directories(DebugControllers INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(DebugControllers PUBLIC
	compiler_flags
	SDL2::SDL2-static
	Constants
	Engine
	Input
	general_assets
	debug_controller_assets
)
