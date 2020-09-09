aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Creatures CSOURCE_LIB)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Spells SSOURCE_LIB)
add_library(lib STATIC ${CSOURCE_LIB} ${SSOURCE_LIB})
