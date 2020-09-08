cmake_minimum_required(VERSION 3.18.2)
set(PROJ_NAME "draugr")
project(${PROJ_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_compile_options(
    -pipe
    -Wall
    -Wextra
    -Werror
    -Wpedantic
)

add_subdirectory(app)
set_target_properties(${PROJ_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../../")
