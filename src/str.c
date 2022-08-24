/**
 * @file str.c
 * @author Enchan1207
 * @brief 文字列型 (string_t) 周りの関数
 * @version v0.2.0
 * @date 2022-08-24
 *
 * @copyright Copyright (c) 2022 Enchan1207
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tinystr.h"

/**
 * @brief 文字列型を初期化
 *
 * @param self 文字列型のポインタ
 * @param initial 初期値 NULLの場合は'\0'となります。
 * @return 成功:0 失敗: -1
 */
int init_string(string_t* self, const char* initial) {
    // 確保メモリ数の計算
    size_t memory_length = 1;
    if (initial != NULL) {
        // 初期値が設定されている場合は、文字列長から確保バイト数を計算する
        memory_length = strlen(initial) + 1;
    }
    self->length = memory_length;

    // 確保
    self->value = (char*)calloc(memory_length, sizeof(char));
    if (self->value == NULL) {
        self->length = 0;
        return -1;
    }
    if (initial != NULL) {
        strcpy(self->value, initial);
    }
    return 0;
}

/**
 * @brief 文字列型のメモリを解放する
 * @param self 文字列型のポインタ
 */
void free_string(string_t* self) {
    self->length = 0;
    free(self->value);
}

/**
 * @brief 文字列型に値を代入する
 *
 * @param self 文字列型のポインタ
 * @param value 代入したい文字列
 * @return 成功:0 失敗: -1
 */
int set_string(string_t* self, const char* value) {
    // すでに確保してある領域で足りるなら、strcpyだけして早期returnという手もある
    // (多分その方が高速)

    // 値に従ってメモリをallocしなおし、代入
    unsigned long new_length = strlen(value) + 1;
    char* tmp = realloc(self->value, new_length * sizeof(char));
    if (tmp == NULL) {
        return -1;
    }
    self->length = new_length;
    self->value = tmp;
    tmp = NULL;

    strcpy(self->value, value);
    return 0;
}

/**
 * @brief メモリダンプ
 *
 * @param self 文字列型のポインタ
 */
void dump_string(string_t* self) {
    printf("struct string (%lu chars, %lu bytes of memory was allocated)\n", strlen(self->value), self->length);
    printf("memory dump from head of str.value (%p):\033[;2m", self->value);
    for (size_t i = 0; i < self->length; i++) {
        if (i % 16 == 0) {
            printf("\n");
        }
        printf("%02X ", self->value[i]);
    }
    puts("\033[0m");
    printf("string representation: %s\n", self->value);
}
