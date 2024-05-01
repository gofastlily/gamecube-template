add_library(Game
	game.cpp
	ball.cpp
	paddle.cpp
	physics.cpp
)

target_include_directories(Game INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(Game PUBLIC
	compiler_flags
	SDL2::SDL2-static
	Input
)

target_link_libraries(Game PRIVATE
	fonts
)
