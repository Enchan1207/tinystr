//
//
//
#include <stdio.h>
#include <stdlib.h>

#include "tinystr.h"

/**
 * @brief 文字列リストのchar**表現を生成
 *
 * @param self
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
