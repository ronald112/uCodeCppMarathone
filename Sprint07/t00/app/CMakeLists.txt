set(SOURCE_EXE main.cpp)
include_directories(src)
add_subdirectory(src)

add_executable(${PROJECT_NAME} ${SOURCE_EXE})
target_link_libraries(${PROJECT_NAME} utils lib)
