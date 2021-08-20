cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(Aqule)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")
add_compile_definitions(AQ_PLATFORM_LINUX)

set(source_core "${PROJECT_SOURCE_DIR}/src/")

set(
	include_dirs ${source_core}
	"${PROJECT_SOURCE_DIR}/src/vendor/GLFW/"
	)

include_directories(${include_dirs})

find_library(glfwlib libglfw.so PATHS "${PROJECT_SOURCE_DIR}/src/vendor/GLFW/lib")

file(GLOB_RECURSE source_core_files "${source_core}/*.cpp")

add_library(aq SHARED ${source_core_files})
target_link_libraries(aq ${glfwlib})