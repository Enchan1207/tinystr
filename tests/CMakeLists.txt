#
# Unittests
#
cmake_minimum_required(VERSION 3.21)

# GoogleTestのフェッチと有効化
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest) # gtest_系関数の読み込み

# tinystr_testターゲットの構成
add_executable(tinystr_test)
target_sources(tinystr_test PRIVATE
    test_string.cpp
    test_string_list.cpp
    test_char_repr.cpp
)
target_link_libraries(tinystr_test PRIVATE
    tinystr
    GTest::gtest_main
)
target_include_directories(tinystr_test
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${GTEST_INCLUDE_DIRS}
)

# テストの実行
gtest_discover_tests(tinystr_test)
