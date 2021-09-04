cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(Aqule VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	add_compile_definitions(AQ_PLATFORM_LINUX)
endif()

if(WIN32)
	# WIN32 not supported
	add_compile_definitions(AQ_PLATFORM_WINDOWS)
endif()

add_compile_definitions(GLFW_INCLUDE_NONE)
add_compile_definitions(SPDLOG_COMPILED_LIB)

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++17")
	add_compile_definitions(AQ_RELEASE)
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -ggdb3 -Wall -std=c++17")
	add_compile_definitions(AQ_DEBUG)
endif()

set(deps "${PROJECT_SOURCE_DIR}/Dependencies")
#####################################################
#					Aqule-Core						#
#####################################################

set(Aqule_src "${PROJECT_SOURCE_DIR}/Aqule-Core/src")
set(Aqule_vendor_src "${PROJECT_SOURCE_DIR}/Aqule-Core/vendor")

include_directories(${Aqule_src})
include_directories(${Aqule_vendor_src})
include_directories(${Aqule_vendor_src}/spdlog/include)

add_subdirectory(Aqule-Core)

#####################################################
#					Aqule-Sandbox					#
#####################################################

set(sandbox_src "${PROJECT_SOURCE_DIR}/Aqule-Sandbox")
include_directories(${sandbox_src})
file(GLOB_RECURSE sandbox_src_files "${sandbox_src}/*.cpp")

add_executable(Aqule ${sandbox_src_files})
target_link_libraries(Aqule PUBLIC "aq")