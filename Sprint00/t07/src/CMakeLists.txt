cmake_minimum_required(VERSION 2.8)

set(PROJ_NAME "inventory_lib")

project(${PROJ_NAME})

function(custom_add_executable_from_dir TARGET)
    file(GLOB SOURCE_LIB ${PROJECT_SOURCE_DIR}/*.cpp)
    add_library(${TARGET} STATIC ${SOURCE_LIB})
endfunction()

custom_add_executable_from_dir(${PROJ_NAME})
