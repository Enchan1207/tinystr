//
//
//
#include <gtest/gtest.h>

#include <string>

#define CPP_STRING(char_arr) std::string(char_arr)

extern "C" {
#include "tinystr.h"
}

// 基本的なStringの扱い
TEST(StringTest, testHandleString) {
    string_t str;

    // 初期化
    const char* initial_value = "Hello,World";
    EXPECT_EQ(init_string(&str, initial_value), 0);

    // .lengthメンバは実際に確保しているメモリ数を返す
    // 文字数ではないので注意
    EXPECT_EQ(str.length, strlen(initial_value) + 1);

    EXPECT_EQ(CPP_STRING(initial_value), CPP_STRING(str.value));

    // 値を書き換えることもできる 内部ではreallocしている
    const char* new_value = "New value (longer than initial value)";
    set_string(&str, new_value);
    EXPECT_EQ(str.length, strlen(new_value) + 1);
    EXPECT_EQ(CPP_STRING(new_value), CPP_STRING(str.value));

    free_string(&str);
}

// C++のstd::stringから生成
TEST(StringTest, testConvertFromCppString) {
    string_t str;

    std::string initial_value = "Hello,World!";
    EXPECT_EQ(init_string(&str, initial_value.c_str()), 0);

    // 内部実装はコピーなので、片方を書き換えても何も起こらない
    set_string(&str, "MODIFIED!!");
    EXPECT_NE(initial_value, CPP_STRING(str.value));

    // 逆も然り
    initial_value = "I was modified too!";
    EXPECT_NE(initial_value, CPP_STRING(str.value));
}
