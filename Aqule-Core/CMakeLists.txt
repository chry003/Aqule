cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(Aqule)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")

set(source_core "${PROJECT_SOURCE_DIR}/Aqule")
include_directories(${source_core})

file(GLOB_RECURSE source_core_files "${source_core}/*.cpp")

add_library(aq SHARED ${source_core_files})