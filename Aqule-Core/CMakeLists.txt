cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(aq VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(GLFW_INCLUDE_NONE)
add_compile_definitions(AQ_PLATFORM_LINUX)
add_compile_definitions(AQ_DEBUG)
add_compile_definitions(AQ_RELEASE)
add_compile_definitions(SPDLOG_COMPILED_LIB)

set(Aqule_src "${PROJECT_SOURCE_DIR}/src")
set(Aqule_vendor_src "${PROJECT_SOURCE_DIR}/vendor")

include_directories(${Aqule_src})
include_directories(${Aqule_vendor_src})
include_directories(${Aqule_vendor_src}/spdlog/include)
include_directories(${Aqule_vendor_src}/imgui)

file(GLOB_RECURSE Aqule_src_files "${Aqule_src}/*.cpp")

find_library(dllib dl-2.33 PATHS "${deps}")
find_library(glfwlib libglfw.so PATHS "${deps}")
find_library(pthreadlib libpthread-2.33.so PATHS "${deps}")

set(lib 
	${dllib} 
	${glfwlib}
	${pthreadlib}
	)

# build spdlog
file(GLOB lib_spdlog_source ${Aqule_vendor_src}/spdlog/src/*.cpp)
set(source_spdlog ${lib_spdlog_source})
add_library(spdlog SHARED ${source_spdlog})
target_link_libraries(spdlog ${CMAKE_DL_LIBS})
target_link_libraries(spdlog ${lib})

# build glad
file(GLOB lib_glad_source ${Aqule_vendor_src}/glad/glad.c)
set(source_glad ${lib_glad_source})
add_library(glad SHARED ${source_glad})
target_link_libraries(glad ${CMAKE_DL_LIBS})
target_link_libraries(glad ${lib})

# build imgui
file(GLOB lib_imgui_source ${Aqule_vendor_src}/imgui/*.cpp)
set(source_imgui ${lib_imgui_source})
add_library(imgui SHARED ${source_imgui})
target_link_libraries(imgui ${CMAKE_DL_LIBS})
target_link_libraries(imgui ${lib})

# build Aqule lib
add_library(aq STATIC ${Aqule_src_files})
target_link_libraries(aq ${CMAKE_DL_LIBS})
target_link_libraries(aq ${lib})
target_link_libraries(aq spdlog)
target_link_libraries(aq glad)
target_link_libraries(aq imgui)
