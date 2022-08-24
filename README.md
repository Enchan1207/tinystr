# tinystr    {#mainpage}

[![CMake](https://github.com/Enchan1207/tinystr/actions/workflows/cmake.yml/badge.svg)](https://github.com/Enchan1207/tinystr/actions/workflows/cmake.yml)

## Overview

tiny string handling library for C

## Setup

To use this library, you need [cmake >= 3.21](https://cmake.org/).
You can choose one of the following ways to use it:

 - [Add as dependency to your project without installing](#add-as-dependency)　(Recommended for general users or CI)
 - [Build and install to your machine](#build-and-install) (Recommended for contributors)

### Add as dependency

Add the following to CMakeLists.txt:

```cmake
# Fetch library
include(FetchContent)
FetchContent_Declare(
    tinystr
    GIT_REPOSITORY https://github.com/Enchan1207/tinystr.git
    GIT_TAG v0.2.0
)
FetchContent_MakeAvailable(tinystr)

# assume target name is main
add_executable(main)
target_sources(main
    ...
)

# Include directories are automatically set when linking
target_link_libraries(main PRIVATE
    tinystr 
)
```

### Build and install

After clone this repository, exec commands shown below.
To exec these commands, the library will be installed on your system.

```
mkdir build
cd build
cmake ..
cmake --build .
ctest
cmake --install .
```

Additionally, this library provides some flags.  
In details, see output of `ccmake`.

## Usage

Under construction...

## License

this repository is published under [MIT License](LICENSE).
