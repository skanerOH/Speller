cmake_minimum_required(VERSION 3.13)
project(Speller)

set(CMAKE_CXX_STANDARD 14)

add_executable(Speller main.cpp DataStructuresToCheck/DataStructure.h DataStructuresToCheck/HashTable.h DataStructuresToCheck/HashTable.cpp DataStructuresToCheck/BinTreeLeaf.h DataStructuresToCheck/BinTreeLeaf.cpp Reader.h Reader.cpp DataStructuresToCheck/TrieLeaf.h DataStructuresToCheck/TrieLeaf.cpp DataStructuresToCheck/STDVector.h DataStructuresToCheck/STDVector.cpp DataStructuresToCheck/STDUnorderedMap.h DataStructuresToCheck/STDUnorderedMap.cpp Checker.h Checker.cpp)