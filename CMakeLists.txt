cmake_minimum_required(VERSION 3.19.2)

project(gl VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

file(GLOB_RECURSE SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_SOURCE_DIR}/src/*.hpp)

add_executable(${CMAKE_PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC glfw glad)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -save-temps -Wall -Wextra -pedantic-errors -Werror)