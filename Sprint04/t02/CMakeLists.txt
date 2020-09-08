cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_STANDARD 17)

set(PROJ_NAME "t02")

project(${PROJ_NAME} LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(utils)
add_subdirectory(app)

