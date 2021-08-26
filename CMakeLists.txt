cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(Aqule VERSION 0.1.0 LANGUAGES CXX C)

add_compile_definitions(AQ_PLATFORM_LINUX)
add_compile_definitions(AQ_DEBUG)
add_compile_definitions(AQ_RELEASE)
add_compile_definitions(SPDLOG_COMPILED_LIB)

if(${CMAKE_BUILD_TYPE} EQUAL "Release")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++17")
endif()

if(${CMAKE_BUILD_TYPE} EQUAL "Debug")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")
endif()

set(deps "${PROJECT_SOURCE_DIR}/Dependencies")

#####################################################
#					Aqule-Core						#
#####################################################
set(Aqule_src "${PROJECT_SOURCE_DIR}/Aqule-Core/src")
set(Aqule_vendor_src "${PROJECT_SOURCE_DIR}/Aqule-Core/vendor")

include_directories(${Aqule_src})
include_directories(${Aqule_vendor_src})
include_directories(${Aqule_vendor_src}/aqlog/include)

file(GLOB_RECURSE Aqule_src_files "${Aqule_src}/*.cpp")

find_library(dllib dl-2.33 PATHS "${deps}")
find_library(glfwlib libglfw.so PATHS "${deps}")
find_library(spdlog libspdlog.so PATHS "${deps}")

# build glad
file(GLOB lib_c ${Aqule_vendor_src}/glad/glad.c)
set(source_glad ${lib_c})
add_library(glad SHARED ${source_glad})
target_link_libraries(glad ${dllib})

# build Aqule lib
add_library(aq SHARED ${Aqule_src_files})
target_link_libraries(aq "glad")
target_link_libraries(aq ${glfwlib})
target_link_libraries(aq ${spdlog})

#####################################################
#					Aqule-Sandbox					#
#####################################################

set(sandbox_src "${PROJECT_SOURCE_DIR}/Aqule-Sandbox")
include_directories(${sandbox_src})
file(GLOB_RECURSE sandbox_src_files "${sandbox_src}/*.cpp")

add_executable(Aqule ${sandbox_src_files})
target_link_libraries(Aqule PUBLIC "aq")