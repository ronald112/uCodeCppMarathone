cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)
project(utils LANGUAGES CXX)
add_library(utils INTERFACE)
target_include_directories(utils INTERFACE .)