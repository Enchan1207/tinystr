cmake_minimum_required(VERSION 3.21)

# 静的ライブラリを生成
add_library(tinystr STATIC)

# ライブラリを生成するのに必要なソース
target_sources(tinystr
    PRIVATE
    tinystr.h
    str.c
    strlist.c
    char_repr.c
)

# コンパイル設定
target_compile_options(tinystr PUBLIC -Wall)
include_directories(${PROJECT_SOURCE_DIR}/src)

# インストール設定
include(GNUInstallDirs)
install(TARGETS tinystr ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES tinystr.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
