cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
project(lab2_treap)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
)
FetchContent_MakeAvailable(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(
  lab2_treap
  src/Lab2_treaps.c
  src/Lab_2_treaps.h
  src/treaps_test.cpp
)

target_link_libraries(
  lab2_treap
  GTest::gtest_main
)