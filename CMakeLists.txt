cmake_minimum_required(VERSION 3.29.5)

project(GameCubeTemplate
	VERSION 0.1.0
	DESCRIPTION "Template to build games for the Nintendo GameCube"
	LANGUAGES C CXX)

# specify the C++ standard
add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_20)

# CMake Modules for SDL2 extras
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Include binary asset preparation tools
include(cmake/bin2h.cmake)
include(cmake/prepare_binary_asset.cmake)

# Prepare constants as a library
add_library(Constants INTERFACE)
target_include_directories(Constants INTERFACE "${PROJECT_SOURCE_DIR}/constants")

###
# Prepare binary assets early
#

# General
file(GLOB general_assets "data/*.png")
foreach(general_asset ${general_assets})
	prepare_binary_asset("${general_asset}")
endforeach()
add_library(GeneralAssets INTERFACE)
target_include_directories(GeneralAssets INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/data")

# Fonts
prepare_binary_asset(
	${PROJECT_SOURCE_DIR}/data/fonts/josefin_sans_regular.ttf
)
add_library(Fonts INTERFACE)
target_include_directories(Fonts INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/data/fonts")

# Debug Controller Assets
file(GLOB debug_controller_assets "data/debug_controller/*.png")
foreach(debug_controller_asset ${debug_controller_assets})
	prepare_binary_asset("${debug_controller_asset}")
endforeach()
add_library(DebugControllerAssets INTERFACE)
target_include_directories(DebugControllerAssets INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/data/debug_controller")

#
# End binary assets
###


# Find required packages
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(ZLIB REQUIRED)

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
	Fonts
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

set(IMGUI_PATH "${PROJECT_SOURCE_DIR}/libraries/imgui")
file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp)
add_library(ImGui STATIC ${IMGUI_SOURCES})
target_include_directories(ImGui PUBLIC ${IMGUI_PATH})
target_link_libraries(ImGui PUBLIC
	${SDL2_LIBRARIES}
)


find_package(Freetype REQUIRED)

# Miscellaneous other libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
	png
	jpeg
	fat
	freetype
	aesnd
	harfbuzz
	ogc
	m
	db
	z
	bz2
)

# Helper to create the .dol file
ogc_create_dol(${PROJECT_NAME})
