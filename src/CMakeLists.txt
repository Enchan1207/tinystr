cmake_minimum_required(VERSION 3.21)

add_library(strings STATIC
    strings.h
    strings.c
)

include_directories(${PROJECT_SOURCE_DIR}/src)
