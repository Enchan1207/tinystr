#
# tinystr
#
cmake_minimum_required(VERSION 3.21)

# プロジェクト情報
project(tinystr
    VERSION 0.1.0
    DESCRIPTION "tiny string handling library for C"
    LANGUAGES C CXX
)

# ライブラリのメインディレクトリ
add_subdirectory(src)

# 依存関係としてビルドされている場合は、tests/ を除外する
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    option(TINYSTR_BUILD_TESTS "whether to build tests" ON)

    if(TINYSTR_BUILD_TESTS)
        message(NOTICE "testing enabled")
        enable_testing()
        set(CMAKE_CXX_STANDARD 14) # GoogleTestはC++14以上が必要
        add_subdirectory(tests)
    endif()
endif()

# インストール構成
install(TARGETS tinystr
    # configファイル (tinystr-config.cmake) を生成
    EXPORT tinystr-config

    # 各ファイルの配置先
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# ヘッダファイルをインストール
install(DIRECTORY ${tinystr_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h"
)

# configファイルをインストールツリーからエクスポート
install(EXPORT tinystr-config
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/tinystr
)

# configファイルを外部プロジェクト用に(インストールせずに)エクスポート
export(EXPORT tinystr-config
    FILE tinystr-config.cmake
)
