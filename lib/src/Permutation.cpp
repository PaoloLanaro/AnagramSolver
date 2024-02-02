//
// Created by Paolo Lanaro on 1/28/2024.
//

#include "../include/Permutation.h"
#include "../include/MergeSortString.h"

using std::string;
using std::vector;

vector<string> Permutation::getPermutations(const string &word) {
    vector<string> validPermutations = vector<string>();
    string sorted = MergeSortString::lexicographicSort(word);
    permutationHelper(sorted, 0, sorted.size() - 1, validPermutations);
    return validPermutations;
}

void
Permutation::permutationHelper(string &permutation, const int &index, const int &end,
                               vector<string> &validPermutations) {
    if (index == end) {
        validPermutations.push_back(permutation);
    } else {
        for (int choices = index; choices <= end; ++choices) {

            std::swap(permutation[index], permutation[choices]);
            permutationHelper(permutation, index + 1, end, validPermutations);
            std::swap(permutation[index], permutation[choices]);
        }
    }
}
