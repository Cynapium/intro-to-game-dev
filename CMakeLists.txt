cmake_minimum_required (VERSION 2.6)

set(PROJECT_NAME GameDev)
set(PROJECT_TEST ${PROJECT_NAME}Test)

project(${PROJECT_NAME})

# Files
file(GLOB FILES_SGDM RELATIVE "src/engine/memory" "*.cpp")
file(GLOB FILES_SGDC RELATIVE "src/engine/containers" "*.cpp")

# Main project
add_executable(${PROJECT_NAME} game.m.cpp ${FILES_SGDM} ${FILES_SGDC})

# Tests
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(${PROJECT_TEST} test.m.cpp)

# Libraries
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)
target_link_libraries(${PROJECT_TEST} ${GTEST_LIBRARIES} pthread)

