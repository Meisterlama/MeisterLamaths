cmake_minimum_required(VERSION 3.17)

project(MeisterLamaths)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(Google_tests)

add_library(MeisterLamaths library.cpp library.h)
