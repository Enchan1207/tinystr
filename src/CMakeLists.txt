cmake_minimum_required(VERSION 3.21)

add_library(tinystr STATIC
    tinystr.h
    str.c
    strlist.c
    char_repr.c
)
target_compile_options(tinystr PUBLIC -Wall)

include_directories(${PROJECT_SOURCE_DIR}/src)
