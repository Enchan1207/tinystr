/**
 * @file tinystr.h
 * @author Enchan1207
 * @brief メインヘッダ
 * @version v0.2.0
 * @date 2022-08-24
 *
 * @copyright Copyright (c) 2022 Enchan1207
 *
 */
#pragma once

/**
 * @struct string_t
 * @brief 文字列型
 */
typedef struct {
    //! 確保されているメモリの長さ
    unsigned long length;

    //! 値へのポインタ
    char* value;
} string_t;

/**
 * @struct string_list
 * @brief 文字列配列
 */
struct string_list {
    //! 要素数
    unsigned long count;

    //! 値へのポインタ
    string_t* value;
};

// ---

int init_string(string_t*, const char*);
void free_string(string_t*);

int set_string(string_t*, const char*);

void dump_string(string_t*);

// ---

int init_string_list(struct string_list*, const unsigned int);
void free_string_list(struct string_list*);

int add_string_list(struct string_list*, const char*);
int set_string_list(struct string_list*, const unsigned int, const char*);
void dump_string_list(struct string_list*);

char** char_repr_string_list(struct string_list*);
