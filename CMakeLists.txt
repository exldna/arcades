cmake_minimum_required(VERSION 3.24)

set(ARCADES_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

if(WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

project(arcades
    VERSION 0.0.1
    LANGUAGES CXX
)

add_subdirectory("${ARCADES_SOURCE_DIR}/ext/utils")
set_property(TARGET utils PROPERTY FOLDER "external")

if(NOT UTIlS_INCLUDE_MODULES_PATH IN_LIST CMAKE_MODULE_PATH)
    list(APPEND CMAKE_MODULE_PATH ${UTIlS_INCLUDE_MODULES_PATH})
endif()

set(ARCADES_LIBRARY_DIR "${ARCADES_SOURCE_DIR}/lib")
add_subdirectory(${ARCADES_LIBRARY_DIR})

set(ARCADES_EXECUTABLE_NAME "arcades")
add_executable(${ARCADES_EXECUTABLE_NAME} "src/main.cxx")

target_link_libraries(${ARCADES_EXECUTABLE_NAME} PUBLIC "arcades-lib")