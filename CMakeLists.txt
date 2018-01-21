cmake_minimum_required(VERSION 3.6)
project(msl_clang_001)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c BSTree.c)

# The variable SOURCE_FILES does not automatically contain
# all .c files needed,  so BSTree.c is added afterwards.
add_executable(msl_clang_001 main.c BSTree.c)