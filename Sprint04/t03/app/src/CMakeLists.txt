cmake_minimum_required(VERSION 3.16.3)

set(PROJ_NAME "src")

project(${PROJ_NAME})

function(custom_add_library_from_dir TARGET)
    file(GLOB SOURCE_LIB ${PROJECT_SOURCE_DIR}/*.cpp)
    add_library(${TARGET} STATIC ${SOURCE_LIB})
endfunction()

custom_add_library_from_dir(${PROJ_NAME})
