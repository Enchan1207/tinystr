//
//
//
#include <gtest/gtest.h>

#include <string>

#define CPP_STRING(char_arr) std::string(char_arr)

extern "C" {
#include "tinystr.h"
}

// 文字列リストの生成
TEST(StringListTest, testCreateStrList) {
    string_list list;

    // 要素数を指定して初期化
    const unsigned int count = 4;
    EXPECT_EQ(init_string_list(&list, count), 0);

    // インデックス指定で値を設定できる
    std::string value = "Hello,World";
    EXPECT_EQ(set_string_list(&list, 0, value.c_str()), 0);

    // ドットアクセスで値を取りに行ける
    EXPECT_EQ(CPP_STRING(list.value[0].value), value);
    dump_string_list(&list);
}

// 文字列リストへの追加
TEST(StringListTest, testAddStrList) {
    string_list list;

    // 初期要素ゼロのリストを生成
    const unsigned int count = 0;
    EXPECT_EQ(init_string_list(&list, count), 0);

    // 追加
    EXPECT_EQ(add_string_list(&list, "Addition!"), 0);
    EXPECT_EQ(list.count, 1);
    dump_string_list(&list);
}
