add_library(Engine
	delta_time.cpp
	tex_2d.cpp
	text.cpp
	timer.cpp
)

target_include_directories(Engine INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/entities")

target_link_libraries(Engine PUBLIC Entities compiler_flags)
