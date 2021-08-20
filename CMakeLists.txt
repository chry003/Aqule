cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(Aqule)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")
set(source_core "${PROJECT_SOURCE_DIR}/Aqule-Core/Aqule")

add_subdirectory("${PROJECT_SOURCE_DIR}/Aqule-Core/")
set(source_sandbox "${PROJECT_SOURCE_DIR}/Aqule-Sandbox/src")

include_directories(${source_core})
include_directories(${source_sandbox})

file(GLOB_RECURSE source_sandbox_files "${source_sandbox}/*.cpp")

add_executable(Aqule ${source_sandbox_files})
target_link_libraries(Aqule "aq")