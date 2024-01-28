//
// Created by Paolo Lanaro on 1/27/2024.
//

#ifndef WORDGAMES_ENGLISHDICTIONARY_H
#define WORDGAMES_ENGLISHDICTIONARY_H

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

class EnglishDictionary {
private:
    bool loadedDict = false;
    std::unordered_map<std::string, std::vector<std::string>> stringToAnagramsMap;
public:
    EnglishDictionary();
    std::vector<std::string> searchForAnagrams(const std::string& key);
};

#endif //WORDGAMES_ENGLISHDICTIONARY_H
