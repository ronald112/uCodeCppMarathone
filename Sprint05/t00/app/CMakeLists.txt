aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_EXE)
include_directories(src)

add_subdirectory(src)

add_executable(draugr ${SOURCE_EXE})
target_link_libraries(draugr lib)
