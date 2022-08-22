//
//
//
#pragma once

/**
 * @struct string_t
 * @brief 文字列型
 */
typedef struct {
    unsigned long length;  // 確保されているメモリの長さ
    char* value;           // 値へのポインタ
} string_t;

// ---

int init_string(string_t*, const char*);
void free_string(string_t*);

int set_string(string_t*, const char*);

void dump_string(string_t*);
