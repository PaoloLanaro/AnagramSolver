//
// Created by Paolo Lanaro on 1/27/2024.
//

#include "../include/EnglishDictionary.h"

using std::string;
using std::vector;

vector<string> EnglishDictionary::searchForAnagrams(const string& key) {
    string keyCopy = key;
    std::sort(keyCopy.begin(), keyCopy.end());
    // Break up the keycopy into each permutation of itself.
    // search for each permutation of itself. 
    vector<string> anagrams = stringToAnagramsMap.at(keyCopy);
    return anagrams;
}

EnglishDictionary::EnglishDictionary() {

    // LOAD STRINGS -> sort by characters (while keeping original words intact) -> map sorted string to vector of values -> ANAGRAMS
    stringToAnagramsMap;
}
