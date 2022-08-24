/**
 * @file char_repr.c
 * @author Enchan1207
 * @brief 文字列配列 (string_list) の char** 表現の実装
 * @version v0.2.0
 * @date 2022-08-24
 *
 * @copyright Copyright (c) 2022 Enchan1207
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "tinystr.h"

/**
 * @brief 文字列リストのchar**表現を生成
 *
 * @param self 文字列リストのポインタ
 * @return 生成されたchar**表現へのポインタ。失敗した場合はNULLが返ります。
 * @note 成功時の戻り値はヒープ領域のアドレスです。適宜freeしてください。
 */
char** char_repr_string_list(struct string_list* self) {
    // メモリ確保
    char** buffer = (char**)calloc(self->count, sizeof(char*));
    if (buffer == NULL) {
        return buffer;
    }

    // メモリにstrへのアドレスを格納
    for (unsigned long i = 0; i < self->count; i++) {
        buffer[i] = self->value[i].value;
    }
    return buffer;
}
