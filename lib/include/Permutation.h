//
// Created by Paolo Lanaro on 1/28/2024.
//

#ifndef WORDGAMES_PERMUTATION_H
#define WORDGAMES_PERMUTATION_H

#include <vector>
#include <string>
#include <unordered_set>

class Permutation {
private:
    static void fullPermutationsHelper(std::string &permutation, const int &index, const int &end);
    static void substringPermutationsHelper(const std::string& permutation);

    static std::unordered_set<std::string> fullPermutations;
    static std::unordered_set<std::string> substringPermutations;
public:

    static std::vector<std::string> getFullPermutations(const std::string &word);
    static std::vector<std::string> getSubstringPermutations(const std::string &word);
};

#endif //WORDGAMES_PERMUTATION_H
