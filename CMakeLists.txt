cmake_minimum_required(VERSION 3.16.3)
project(gl VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

set(VENDOR_DIR ${CMAKE_SOURCE_DIR}/vendor)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/deps)

file(GLOB_RECURSE SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_SOURCE_DIR}/src/*.hpp)

add_subdirectory(vendor/glfw ${LIB_DIR}/glfw)
add_subdirectory(vendor/glad ${LIB_DIR}/glad)

add_executable(${CMAKE_PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC glfw glad)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ${VENDOR_DIR}/glfw/include
    ${LIB_DIR}/glad/include/glad)

# "-save-temps" required for dseight/vscode-disasexpl
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -save-temps -Wall -Wextra -pedantic-errors -Werror)