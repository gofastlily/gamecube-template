add_library(Utils
	framerate.cpp
	utils.cpp
	draw_box2d.cpp
)

target_include_directories(Utils INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(Utils PUBLIC
	compiler_flags
	Box2d
	ImGui
	general_assets
	debug_controller_assets
)
