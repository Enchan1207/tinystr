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

/**
 * @struct string_list
 * @brief 文字列配列
 */
struct string_list {
    unsigned long count;  // 要素数
    string_t* value;      // 値へのポインタ
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
