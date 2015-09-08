cmake_minimum_required (VERSION 2.6)

set(PROJECT_NAME GameDev)
set(LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} game.m.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBS_DIR}/libgtest.so
${LIBS_DIR}/libgtest_main.so pthread)

