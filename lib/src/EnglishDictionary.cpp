//
// Created by Paolo Lanaro on 1/27/2024.
//

#include "../include/EnglishDictionary.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_set>
#include "../include/MergeSortString.h"

using std::string;
using std::vector;
using std::fstream;

vector<string> EnglishDictionary::searchWordForAnagrams(const string &key) {
    string sortedKey = MergeSortString::lexicographicSort(key);
    // Break up the keycopy into each permutation of itself.
    // search for each permutation of itself.
    vector<string> anagrams;
    if (stringToAnagramsMap.count(sortedKey) > 0) {
        anagrams = stringToAnagramsMap[sortedKey];
        return anagrams;
    } else {
        throw std::invalid_argument("The key key you passed in doesn't have any anagrams.");
    }
}

EnglishDictionary::EnglishDictionary() : stringToAnagramsMap() {

    std::ifstream file("../english_words/enable1.txt");
    int flag = 0;

    string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (flag < 0) {
                line.erase(std::remove(line.begin(), line.end(), '\r' ), line.end());
            } else if (flag == 0) {
                if (line.substr(line.size() - 1, 1) == "\r") {
                    --flag;
                    line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
                } else {
                    ++flag;
                }
            }
            string sortedWord = MergeSortString::lexicographicSort(line);
            stringToAnagramsMap[sortedWord].push_back(line);
        }
    } else {
        std::cerr << "Could not open dictionary file" << std::endl;
    }
    // LOAD STRINGS -> sort by characters (while keeping original words intact) -> map sorted string to vector of values -> ANAGRAMS
}

vector<string> EnglishDictionary::searchVectorForAnagrams(const vector<string> &keys) {
    std::unordered_set<string> anagrams;
    vector<string> result;

    for (const string &key : keys) {
        try {
            vector<string> anagramVector = searchWordForAnagrams(key);
            for (const string &anagram: anagramVector) {
                anagrams.insert(anagram);
            }
        } catch (std::invalid_argument &error) {
            std::cerr << key << " has no valid anagrams." << std::endl;
        }
    }
    std::cout << std::endl;

    for (const string& word : anagrams) {
        result.push_back(word);
    }
    return result;
}
