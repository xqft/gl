cmake_minimum_required(VERSION 3.16.3)
project(gl VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

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

### Compile flags ###
set(DEBUG_COMPILE_OPTIONS "-g3" "-ggdb" "-DNDEBUG")
set(RELEASE_COMPILE_OPTIONS)

### Application ###

add_executable(${CMAKE_PROJECT_NAME}) 
include(sources)

if(MSVC)
    target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC "/Wall")
else()
    # "-save-temps" required for dseight/vscode-disasexpl
    # https://stackoverflow.com/questions/34948142/gcc-wall-pedantic-wextra-in-visual-studio
    target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC "-save-temps" "-Wall" "-Wextra" "-pedantic-errors")
    target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_COMPILE_OPTIONS}>")
    target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_COMPILE_OPTIONS}>")
endif()

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC glfw glad glm)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${VENDOR_DIR}/glfw/include
    ${DEPS_DIR}/glad/include)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CXX_FLAGS})
