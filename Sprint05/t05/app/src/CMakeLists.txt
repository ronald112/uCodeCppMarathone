cmake_minimum_required(VERSION 3.1)

file(GLOB CPPS "*.cpp")
add_library(lib ${CPPS})
target_include_directories(lib INTERFACE
							${CMAKE_CURRENT_SOURCE_DIR}
							)