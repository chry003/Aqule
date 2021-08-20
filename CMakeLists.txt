cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(Aqule)

# add_definitions(-DAQ_PLATFORM_LINUX)

add_compile_definitions(AQ_PLATFORM_LINUX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")
set(source_core "${PROJECT_SOURCE_DIR}/Aqule-Core/src")

add_subdirectory("${PROJECT_SOURCE_DIR}/Aqule-Core/")
set(source_sandbox "${PROJECT_SOURCE_DIR}/Aqule-Sandbox/src")

include_directories(${source_core})
include_directories(${source_sandbox})

file(GLOB_RECURSE source_sandbox_files "${source_sandbox}/*.cpp")

add_executable(Aqule ${source_sandbox_files})
target_link_libraries(Aqule PUBLIC "aq")