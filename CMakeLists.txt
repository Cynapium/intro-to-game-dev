cmake_minimum_required (VERSION 2.6)


###############################################################################
### GENERAL PARAMETERS
###############################################################################

# Variables
set(PROJECT_NAME GameDev)
set(PROJECT_TEST ${PROJECT_NAME}Test)

# Project name
project(${PROJECT_NAME})

# Files
file(GLOB FILES_SGDM RELATIVE "src/engine/memory" "*.cpp")
file(GLOB FILES_SGDC RELATIVE "src/engine/containers" "*.cpp")

#get_cmake_property(_variableNames VARIABLES)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()

# Set flags to compile C++11 with G++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")


###############################################################################
### GTEST
###############################################################################

# Enable ExternalProject CMake module and set default rood directory
include(ExternalProject)
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/libs)

# Add gtest
# http://stackoverflow.com/questions/9689183/cmake-googletest
ExternalProject_Add(
    googletest
    URL http://googletest.googlecode.com/files/gtest-1.7.0.zip

    # Disable install step and log output
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON)

# Get properties from googletest
ExternalProject_Get_Property(googletest source_dir)
ExternalProject_Get_Property(googletest binary_dir)

# Set include directory and library parameters
set(GTEST_INCLUDE_DIR ${source_dir}/include)
set(GTEST_LIBRARY_PATH ${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a)
set(GTEST_LIBRARY gtest)

# Add library
include_directories(${GTEST_INCLUDE_DIR})
add_library(${GTEST_LIBRARY} UNKNOWN IMPORTED)
set_property(TARGET ${GTEST_LIBRARY} PROPERTY IMPORTED_LOCATION
                ${GTEST_LIBRARY_PATH} )
add_dependencies(${GTEST_LIBRARY} googletest)


###############################################################################
### EXECUTABLE & LINK
###############################################################################

# Main Project
add_executable(${PROJECT_NAME} game.m.cpp
    "src/engine/memory/stack_guard.cpp"
    "src/engine/memory/iallocator.cpp"
    "src/engine/memory/default_allocator.cpp"
    "src/engine/memory/counting_allocator.cpp"
    "src/engine/containers/dynamic_array.cpp"
    "src/engine/containers/node.cpp"
    "src/engine/containers/map.cpp"
    "src/engine/data/json_entity.cpp"
    "src/engine/data/json_primitive.cpp"
    "src/engine/data/json_object.cpp"
    "src/engine/data/json_array.cpp"
    "src/engine/data/json_parser.cpp"
    )
target_link_libraries(${PROJECT_NAME} pthread)

# Test suite
add_executable(${PROJECT_TEST} test.m.cpp
    "src/engine/memory/iallocator.cpp"
    "src/engine/memory/default_allocator.cpp"
    "src/engine/memory/counting_allocator.cpp"
    "src/engine/containers/dynamic_array.cpp"
    "src/engine/containers/node.cpp"
    "src/engine/containers/map.cpp")
target_link_libraries(${PROJECT_TEST} ${GTEST_LIBRARY} pthread)


