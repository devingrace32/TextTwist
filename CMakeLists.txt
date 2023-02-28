cmake_minimum_required(VERSION 3.9)
project(BinaryTrie)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -Wextra -pedantic -pedantic-errors")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
        Trie.h Trie.cpp TrieNode.h TrieNode.cpp TextTwist.cpp TrieNode.cpp)

add_executable(BinaryTrie ${SOURCE_FILES})