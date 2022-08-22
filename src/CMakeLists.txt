cmake_minimum_required(VERSION 3.21)

add_library(tinystr STATIC
    tinystr.h
    tinystr.c
)
target_compile_options(tinystr PUBLIC -Wall)

include_directories(${PROJECT_SOURCE_DIR}/src)
