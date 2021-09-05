cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(aq VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(GLFW_INCLUDE_NONE)
add_compile_definitions(AQ_PLATFORM_LINUX)
add_compile_definitions(AQ_DEBUG)

set(Aqule_src "${PROJECT_SOURCE_DIR}/src")
set(Aqule_vendor_src "${PROJECT_SOURCE_DIR}/vendor")

include_directories(${Aqule_src})
include_directories(${Aqule_vendor_src})
include_directories(${Aqule_vendor_src}/glad)
include_directories(${Aqule_vendor_src}/glm)
include_directories(${Aqule_vendor_src}/imgui)
include_directories(${Aqule_vendor_src}/imgui/backends)
include_directories(${Aqule_vendor_src}/spdlog/include)

file(GLOB_RECURSE Aqule_src_files "${Aqule_src}/*.cpp")

find_library(glfwlib libglfw.so PATHS "${deps}")
find_library(dllib libdl-2.33.so PATHS "${deps}")

# subdir
add_subdirectory(${Aqule_vendor_src}/glad)
add_subdirectory(${Aqule_vendor_src}/imgui)
add_subdirectory(${Aqule_vendor_src}/spdlog)

# build Aqule lib
add_library(aq STATIC ${Aqule_src_files})
target_link_libraries(aq "glad")
target_link_libraries(aq "imgui")
target_link_libraries(aq "spdlog")
target_link_libraries(aq ${dllib})
target_link_libraries(aq ${glfwlib})