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
    static void permutationHelper(std::string &permutation, const int &index, const int &end,
                                  std::unordered_set<std::string> &permutations);

public:
    static std::vector<std::string> getPermutations(const std::string &word);
};

#endif //WORDGAMES_PERMUTATION_H
