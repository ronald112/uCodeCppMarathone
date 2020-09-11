cmake_minimum_required(VERSION 3.18.2)

project(utils LANGUAGES CXX)
add_library(utils INTERFACE)
target_include_directories(utils INTERFACE .)