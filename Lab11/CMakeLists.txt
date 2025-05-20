cmake_minimum_required(VERSION 3.30)
project(OOP_lab11)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP_lab11 main.cpp Sort.h)

# fetch Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# add an executable test target
add_executable(
        OOP_lab11_test
        main_test.cpp
)

# link the Google Test library
target_link_libraries(
        OOP_lab11_test
        gtest_main
)

# enable CMake's test runner to discover the tests included in the binary,
# using the GoogleTest CMake module
include(GoogleTest)
gtest_discover_tests(OOP_lab11_test)