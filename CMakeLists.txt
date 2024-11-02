cmake_minimum_required(VERSION 3.13)

project(GameCubeTemplate
	VERSION 0.1.0
	DESCRIPTION "Template to build games for the Nintendo GameCube"
	LANGUAGES C CXX
)

# specify the C++ standard
add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_20)

# Prepare constants as a library
add_library(Constants INTERFACE)
target_include_directories(Constants INTERFACE "${PROJECT_SOURCE_DIR}/constants")

# Fonts
file(GLOB font_files CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/data/fonts/*.ttf")
dkp_add_embedded_binary_library(fonts ${font_files})

# General assets
file(GLOB general_assets_files CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/data/*.png")
dkp_add_embedded_binary_library(general_assets ${general_assets_files})

# Debug controller assets
file(GLOB debug_controller_assets_files CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/data/debug_controller/*.png")
dkp_add_embedded_binary_library(debug_controller_assets ${debug_controller_assets_files})

# Find required packages
find_package(GLU REQUIRED)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2-static)
find_package(SDL2 CONFIG COMPONENTS SDL2main)
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

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
	GLU
	SDL2::SDL2-static
	SDL2_ttf::SDL2_ttf-static
	SDL2_image::SDL2_image-static
	SDL2_mixer::SDL2_mixer-static
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
	SDL2::SDL2-static
)

# Helper to create the .dol file
ogc_create_dol(${PROJECT_NAME})
