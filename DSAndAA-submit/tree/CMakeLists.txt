cmake_minimum_required(VERSION 3.12)

aux_source_directory(. DIR_SRCS)

add_executable(main Main.cpp)
add_executable(huffman HuffmanTree.cpp)