cmake_minimum_required(VERSION 3.21)

add_library(tinystr STATIC
    tinystr.h
    tinystr.c
)

include_directories(${PROJECT_SOURCE_DIR}/src)
