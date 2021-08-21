cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(Aqule)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")
add_compile_definitions(AQ_PLATFORM_LINUX)

set(source_core "${PROJECT_SOURCE_DIR}/src/")

include_directories(${source_core})
include_directories("${PROJECT_SOURCE_DIR}/Vendor/")

file(GLOB lib_c Vendor/glad/glad.c)
set(source_glad ${lib_c})

find_library(
		dllib dl-2.33 
		PATHS "${PROJECT_SOURCE_DIR}/Dependencies"
	)
add_library(glad STATIC ${source_glad})
target_link_libraries(glad ${dllib})


find_library(
		glfwlib libglfw.so 
		PATHS "${PROJECT_SOURCE_DIR}/Dependencies"
	)

file(GLOB_RECURSE source_core_files "${source_core}/*.cpp")

add_library(aq SHARED ${source_core_files})
target_link_libraries(aq "glad")
target_link_libraries(aq ${glfwlib})