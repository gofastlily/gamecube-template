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
	ImGui
	Box2d
)
