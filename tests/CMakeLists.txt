#
# Unittests
#
cmake_minimum_required(VERSION 3.21)

# cofigure unittest using GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# generate testcases
add_executable(strings_test
    test_strings.cpp
)
target_link_libraries(strings_test
    strings
    GTest::gtest_main
)
include_directories(${PROJECT_SOURCE_DIR}/src ${GTEST_INCLUDE_DIRS})

gtest_discover_tests(strings_test)
