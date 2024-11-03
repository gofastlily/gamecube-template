cmake_minimum_required(VERSION 3.13)

project(GameCubeTemplate
	VERSION 0.1.0
	DESCRIPTION "Template to build games for the Nintendo GameCube"
	LANGUAGES C CXX)

# specify the C++ standard
add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_20)

# Prepare constants as a library
add_library(Constants INTERFACE)
target_include_directories(Constants INTERFACE "${PROJECT_SOURCE_DIR}/constants")

###
# Prepare binary assets early
#

# Fonts
file(GLOB font_files  "${PROJECT_SOURCE_DIR}/data/fonts/*.ttf")
dkp_add_embedded_binary_library(fonts ${font_files})

# General
file(GLOB general_assets_files "${PROJECT_SOURCE_DIR}/data/*.png")
dkp_add_embedded_binary_library(general_assets ${general_assets_files})
# Debug Controller Assets
file(GLOB debug_controller_assets_files "${PROJECT_SOURCE_DIR}/data/debug_controller/*.png")
dkp_add_embedded_binary_library(debug_controller_assets ${debug_controller_assets_files})


#
# End binary assets
###


# Find required packages - doesn't work :/
#find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2 SDL2_image SDL2_mixer SDL2_ttf)
#find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

# Find required packages - does work, meh
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Add source module directories
add_subdirectory("${PROJECT_SOURCE_DIR}/source/engine")
add_subdirectory("${PROJECT_SOURCE_DIR}/source/input")
add_subdirectory("${PROJECT_SOURCE_DIR}/source/utils")
add_subdirectory("${PROJECT_SOURCE_DIR}/source/game")

# Add optional source includes
add_subdirectory("${PROJECT_SOURCE_DIR}/source/utils/debug_controllers")

# Add the executable
add_executable(${PROJECT_NAME}
	${PROJECT_SOURCE_DIR}/source/main.cpp
)

target_include_directories(${PROJECT_NAME} INTERFACE
	"${PROJECT_SOURCE_DIR}/source"
)

target_link_libraries(${PROJECT_NAME} PUBLIC compiler_flags)

# Required source includes
target_link_libraries(${PROJECT_NAME} PUBLIC
	Engine
	Input
	Utils
	Game
)

# Optional source includes
target_link_libraries(${PROJECT_NAME} PUBLIC
	DebugControllers
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	SDL2::SDL2
	SDL2::SDL2main
	SDL2_ttf
	SDL2_image
	SDL2_mixer
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	fonts
	general_assets
	debug_controller_assets
)

set(IMGUI_PATH "${PROJECT_SOURCE_DIR}/libraries/imgui")
file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp)
add_library(ImGui STATIC ${IMGUI_SOURCES})
target_include_directories(ImGui PUBLIC ${IMGUI_PATH})
target_link_libraries(ImGui PUBLIC
	${SDL2_LIBRARIES}
)


find_package(Freetype REQUIRED)


# Helper to create the .dol file
ogc_create_dol(${PROJECT_NAME})
