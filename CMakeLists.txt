cmake_minimum_required(VERSION 3.16.3)
#project(gl VERSION 0.1.0 LANGUAGES C CXX)
project(gl VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

### Compile flags ###

# https://stackoverflow.com/questions/34948142/gcc-wall-pedantic-wextra-in-visual-studio
if(CMAKE_COMPILER_IS_GNUCXX)
    # "-save-temps" required for dseight/vscode-disasexpl
    set(CMAKE_CXX_FLAGS "-save-temps -Wall -Wextra -pedantic-errors")
endif(CMAKE_COMPILER_IS_GNUCXX)

### Directory paths ###

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(VENDOR_DIR ${CMAKE_SOURCE_DIR}/vendor)
set(DEPS_DIR ${CMAKE_SOURCE_DIR}/deps)

### Dependencies ###

add_subdirectory(${VENDOR_DIR}/glfw ${DEPS_DIR}/glfw)
set(GLFW_BUILD_EXAMPLES false)
set(GLFW_BUILD_TESTS false)
set(GLFW_BUILD_DOCS false)

add_subdirectory(${VENDOR_DIR}/glad ${DEPS_DIR}/glad)
set(GLAD_PROFILE "core")
set(GLAD_GENERATOR "cpp")

add_subdirectory(${VENDOR_DIR}/glm ${DEPS_DIR}/glm)

### Application ###

add_executable(${CMAKE_PROJECT_NAME} ${CXX_SOURCE_FILES}) 
include(sources)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC glfw glad glm)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${VENDOR_DIR}/glfw/include
    ${DEPS_DIR}/glad/include)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CXX_FLAGS})
