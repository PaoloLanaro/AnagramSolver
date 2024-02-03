cmake_minimum_required(VERSION 3.22)
project(WordGames)

set(CMAKE_CXX_STANDARD 14)

add_executable(WordGames
        driver.cpp
        lib/src/EnglishDictionary.cpp
        lib/include/EnglishDictionary.h
        lib/include/Permutation.h
        lib/src/Permutation.cpp
        lib/include/MergeSortString.h
        lib/src/MergeSortString.cpp
        lib/include/AVLMap.h)
