add_library(Utils
	framerate.cpp
	utils.cpp
)

target_include_directories(Utils INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/debug_controllers")

target_link_libraries(Utils PUBLIC
	DebugControllers
	compiler_flags
	ImGui
)
