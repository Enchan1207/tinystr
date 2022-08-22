//
//
//
#include <gtest/gtest.h>

#include <string>

#define CPP_STRING(char_arr) std::string(char_arr)

extern "C" {
#include <stdlib.h>

#include "tinystr.h"
}

// char**表現の生成
TEST(CharPtrReprTest, testCharPointerRepresentation) {
    string_list list;
    init_string_list(&list, 4);

    // 適当な値を放り込む
    set_string_list(&list, 0, "/path/to/program");
    set_string_list(&list, 1, "-i");
    set_string_list(&list, 2, "/path/to/input");
    set_string_list(&list, 3, "-v");

    // char**表現を生成
    char** char_repr = char_repr_string_list(&list);

    // 比較
    for (size_t i = 0; i < list.count; i++) {
        std::string str_in_list(list.value[i].value);
        std::string str_in_repr(char_repr[i]);
        EXPECT_EQ(str_in_list, str_in_repr);
    }

    // char**の方を入れ替えることは可能 ただし、元のリストの構造は変わらない
    char* tmp = char_repr[0];
    char_repr[0] = char_repr[1];
    char_repr[1] = tmp;

    EXPECT_NE(CPP_STRING(char_repr[0]), CPP_STRING(list.value[0].value));
    EXPECT_EQ(CPP_STRING(char_repr[0]), CPP_STRING(list.value[1].value));

    // 中身を入れ替えた場合はその限りではない
    set_string_list(&list, 3, "NEW_VALUE");
    EXPECT_EQ(CPP_STRING(char_repr[3]), CPP_STRING(list.value[3].value));

    // しかし、これは **やってはいけない**
    // しっかりチェックせずに単純に置き換えるとバッファオーバーランを起こす可能性がある
    // (このテストケースでは、"Hello, World" が "/path/to/input" より短いので偶然パスするだけ)
    //
    // ちょっと関数として危険かもしれない
    const char* newvalue = "Hello, World";
    strcpy(char_repr[2], newvalue);
    EXPECT_EQ(CPP_STRING(char_repr[2]), CPP_STRING(list.value[2].value));
}
