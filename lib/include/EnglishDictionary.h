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
    std::vector<std::string> searchWordForAnagrams(const std::string &key);
    std::vector<std::string> searchVectorForAnagrams(const std::vector<std::string> &keys);
};

#endif //WORDGAMES_ENGLISHDICTIONARY_H
