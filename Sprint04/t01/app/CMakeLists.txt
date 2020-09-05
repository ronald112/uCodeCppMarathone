cmake_minimum_required(VERSION 3.16.3)

set(PROJ_NAME "imperialVsStormcloak")
project(${PROJ_NAME} LANGUAGES CXX)
set(SOURCE_EXE main.cpp)
add_subdirectory(src)

add_compile_options(
        -std=c++17
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-parameter
)

add_executable(${PROJ_NAME} ${SOURCE_EXE})
target_link_libraries(${PROJ_NAME} utils src)

set_target_properties(${PROJ_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../../")
