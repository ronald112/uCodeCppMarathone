cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)

set(LIB_NAME "lib")
set(PROJ_NAME "tesLibrary")

project(${PROJ_NAME})

function(custom_add_executable_from_dir TARGET)
    file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
    add_executable(${TARGET} ${SRC_FILES})
endfunction()

include_directories(src)

custom_add_executable_from_dir(${PROJ_NAME})

add_subdirectory(src)

target_link_libraries(${PROJ_NAME} ${LIB_NAME})

set_target_properties(${PROJ_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../")
