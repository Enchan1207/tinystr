#
# cmake
#

# バージョン
cmake_minimum_required(VERSION 3.21)

include(GNUInstallDirs) # to define CMAKE_INSTALL_XXXDIR
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

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
target_include_directories(tinystr
    PRIVATE
    ${tinystr_SOURCE_DIR}/include

    INTERFACE
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>
)
target_compile_options(tinystr PRIVATE
    -Wall
)

# インストール構成
install(TARGETS tinystr
    EXPORT tinystr-export # tinystr-config.cmakeを生成する

    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY ${tinystr_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h"
)

install(EXPORT tinystr-export
    FILE tinystr-config.cmake
    DESTINATION share/cmake/tinystr
)
