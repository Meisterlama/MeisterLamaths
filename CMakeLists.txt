cmake_minimum_required(VERSION 3.17)

project(MeisterLamaths)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(tests)

file(GLOB_RECURSE SRC
        src/*.c
        src/*.cpp)

file(GLOB_RECURSE HEADERS
        include/*.hpp)

include_directories(include)

add_library(MeisterLamaths STATIC ${HEADERS})
set_target_properties(MeisterLamaths PROPERTIES LINKER_LANGUAGE CXX)
