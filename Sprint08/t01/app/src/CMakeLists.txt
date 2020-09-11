function(custom_add_library_from_dir TARGET)
    add_library(${TARGET} INTERFACE)
    target_include_directories(${TARGET} INTERFACE .)
endfunction()

custom_add_library_from_dir("lib")
