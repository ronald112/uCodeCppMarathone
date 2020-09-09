aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_LIB)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Player PSOURCE_LIB)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Containers CSOURCE_LIB)
add_library(lib STATIC ${SOURCE_LIB} ${PSOURCE_LIB} ${CSOURCE_LIB})
