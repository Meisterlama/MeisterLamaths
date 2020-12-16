cmake_minimum_required(VERSION 3.17)

project(MeisterLamaths)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(tests)

file(GLOB_RECURSE SRC
        src/*.c
        src/*.cpp)include

add_library(MeisterLamaths STATIC ${SRC})
