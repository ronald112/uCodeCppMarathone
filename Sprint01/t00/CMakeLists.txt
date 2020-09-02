cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)

set(PROJ_NAME "simpleSort")

project(${PROJ_NAME})

function(custom_add_executable_from_dir TARGET)
    file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
    add_executable(${TARGET} ${SRC_FILES})
endfunction()

include_directories(src)

custom_add_executable_from_dir(${PROJ_NAME})

set_target_properties(${PROJ_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../")
