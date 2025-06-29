cmake_minimum_required(VERSION 3.15..4.0)

project(hello_world LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options("/Zc:__cplusplus")
endif()

add_executable(hello_world hello_world.cpp)
