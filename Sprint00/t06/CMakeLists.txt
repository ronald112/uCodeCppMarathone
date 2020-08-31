cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)

project(meadSong)

set(SOURCE main.cpp meadSong.cpp)

set(HEADER meadSong.h)

add_executable(meadSong ${SOURCE} ${HEADER})
