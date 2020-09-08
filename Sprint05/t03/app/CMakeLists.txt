aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_EXE)
include_directories(src)
set(PROJ_NAME "draugr")

add_subdirectory(src)

add_executable(${PROJ_NAME} ${SOURCE_EXE})
target_link_libraries(${PROJ_NAME} lib)
