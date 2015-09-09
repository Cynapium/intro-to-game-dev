cmake_minimum_required (VERSION 2.6)

set(PROJECT_NAME GameDev)
project(${PROJECT_NAME})

# GTests
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} game.m.cpp)

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)

