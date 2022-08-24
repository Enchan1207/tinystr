#
# cmake
#

# バージョン
cmake_minimum_required(VERSION 3.21)

include(GNUInstallDirs) # to define CMAKE_INSTALL_XXXDIR

# オプション定義
option(TINYSTR_BUILD_SHARED_LIBS "whether tinystr should be built as shared-library" OFF)

# tinystrターゲットの構成
if(TINYSTR_BUILD_SHARED_LIBS)
    add_library(tinystr SHARED)
else()
    add_library(tinystr STATIC)
endif()

target_sources(tinystr PRIVATE
    str.c
    strlist.c
    char_repr.c
)
target_include_directories(tinystr PRIVATE
    ${tinystr_SOURCE_DIR}/include
)
target_include_directories(tinystr INTERFACE
    $<BUILD_INTERFACE:${tinystr_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>
)
target_compile_options(tinystr PRIVATE
    -Wall
)
