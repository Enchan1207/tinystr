//
//
//
#include <stdio.h>
#include <stdlib.h>

#include "tinystr.h"

/**
 * @brief 要素数を指定して文字列リストを初期化
 *
 * @param self 文字列リストのポインタ
 * @param count 要素数
 * @return 成功:0/失敗:-1
 */
int init_string_list(struct string_list* self, const unsigned int count) {
    // メモリ確保
    // malloc(0)はマズいので、count=0でもとりあえず1個分は確保する
    // 実装的には無理があるけど、_string_list系関数を使う限り問題ない
    // (dumpするときに一つ多く出力されるくらい、add/setするぶんにはself.countの値で判定がかかるので)
    const unsigned int real_count = count == 0 ? 1 : count;
    self->value = (string_t*)calloc(real_count == 0 ? 1 : real_count, sizeof(string_t));
    if (self->value == NULL) {
        self->count = 0;
        return -1;
    }

    // 各文字列を初期化
    for (unsigned int i = 0; i < real_count; i++) {
        if (init_string(self->value + i, NULL) == 0) {
            continue;
        }

        // 初期化に失敗したら、そこまでに確保した全てのメモリを解放して戻る
        for (unsigned int j = 0; j <= i; j++) {
            free_string(self->value + j);
        }
        free(self->value);
        return -1;
    }

    // countは、「確保されており、使用可能な要素数」であってほしいので
    // 最後に代入
    self->count = count;
    return 0;
}

/**
 * @brief 文字列リストのメモリを解放
 *
 * @param self 文字列リストのポインタ
 */
void free_string_list(struct string_list* self) {
    for (unsigned int i = 0; i < self->count; i++) {
        free_string(self->value + i);
    }
    free(self->value);
}

/**
 * @brief 文字列リストの指定位置の値を設定
 *
 * @param self 文字列リストのポインタ
 * @param index 設定したい文字列のインデックス
 * @param value 設定する値
 * @return 成功:0/失敗:-1
 */
int set_string_list(struct string_list* self, const unsigned int index, const char* value) {
    // 範囲チェック
    if (index >= self->count) {
        return -1;
    }

    // 書き換え
    string_t* target = self->value + index;
    return set_string(target, value);
}

/**
 * @brief 文字列リストに新しい要素を追加
 *
 * @param self 文字列リストのポインタ
 * @param value 新しく追加したい文字列
 * @return 成功:0/失敗:-1
 */
int add_string_list(struct string_list* self, const char* value) {
    // インデックス再割り当て
    unsigned long new_length = self->count + 1;
    string_t* tmp = realloc(self->value, new_length * sizeof(string_t));
    if (tmp == NULL) {
        return -1;
    }
    self->count = new_length;
    self->value = tmp;
    tmp = NULL;

    // 文字列生成+一番最後に代入
    return init_string(self->value + (self->count - 1), value);
}

/**
 * @brief 文字列リストをダンプ
 *
 * @param self 文字列リストのポインタ
 */
void dump_string_list(struct string_list* self) {
    printf("struct string_list (%lu elements)\n", self->count);
    for (unsigned int i = 0; i < self->count; i++) {
        dump_string(self->value + i);
    }
}
