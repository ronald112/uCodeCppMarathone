cmake_minimum_required(VERSION 3.18.2)
project(multithreadedFileHandler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wpedantic
)

add_subdirectory(app)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../../")
