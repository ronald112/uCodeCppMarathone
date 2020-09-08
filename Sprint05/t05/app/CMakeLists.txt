cmake_minimum_required(VERSION 3.1)

project(werewolf LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -Wall -Wextra -Werror -Wpedantic -Wno-unused-parameter")

option(USE_SRC "use src" ON)

if(USE_SRC)
  add_subdirectory(src)
  list(APPEND EXTRA_LIBS lib)
endif()

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})
target_include_directories(	${PROJECT_NAME} PUBLIC
							"${PROJECT_BINARY_DIR}"
							)