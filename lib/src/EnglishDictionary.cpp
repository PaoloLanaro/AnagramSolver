//
// Created by Paolo Lanaro on 1/27/2024.
//

#include "../include/EnglishDictionary.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "../include/MergeSortString.h"

using std::string;
using std::vector;
using std::fstream;

vector<string> EnglishDictionary::searchForAnagrams(const string &key) {
    string sortedKey = MergeSortString::lexicographicSort(key);
    // Break up the keycopy into each permutation of itself.
    // search for each permutation of itself. 
    vector<string> anagrams = stringToAnagramsMap.at(sortedKey);
    return anagrams;
}

EnglishDictionary::EnglishDictionary() : stringToAnagramsMap() {

    std::ifstream file("../english_words/enable1.txt");

    string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            string sortedWord = MergeSortString::lexicographicSort(line);
            stringToAnagramsMap[sortedWord].push_back(line);
        }
    } else {
        std::cerr << "Could not open dictionary file" << std::endl;
    }
    // LOAD STRINGS -> sort by characters (while keeping original words intact) -> map sorted string to vector of values -> ANAGRAMS
}
