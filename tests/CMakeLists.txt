project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

set(USE_DOUBLE_PRECISION OFF)
set(INLINE_FUNCTIONS ON)

if (USE_DOUBLE_PRECISION)
    add_compile_definitions(USE_DOUBLE_PRECISION)
endif ()

if (INLINE_FUNCTIONS)
    add_compile_definitions(INLINE_FUNCTIONS)
endif ()

set(TESTS
        Vector2Test.cpp
        Vector3Test.cpp
        Vector4Test.cpp
        NoiseTest.cpp
        )

# adding the Google_Tests_run target
add_executable(Google_Tests_run ${TESTS})

target_link_libraries(Google_Tests_run gtest gtest_main)