project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

# adding the Google_Tests_run target
add_executable(Google_Tests_run Vector2Test.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)