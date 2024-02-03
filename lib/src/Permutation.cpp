//
// Created by Paolo Lanaro on 1/28/2024.
//

#include <algorithm>
#include "../include/Permutation.h"
#include "../include/MergeSortString.h"

using std::string;
using std::vector;
using std::unordered_set;

vector<string> Permutation::getPermutations(const string &word) {
    unordered_set<string> validPermutations; // temporary set to avoid duplicates.
    string sorted = MergeSortString::lexicographicSort(word);
    permutationHelper(sorted, 0, sorted.size() - 1, validPermutations);

    vector<string> result; // convert set to a sort of "output container" of vector.
    for (const auto &permutation : validPermutations) {
        result.push_back(permutation);
    }
    std::sort(result.begin(), result.end());
    return result;
}

void Permutation::permutationHelper(string &permutation, const int &index, const int &end,
                               unordered_set<string> &validPermutations) {
    if (index == end) {
        validPermutations.insert(permutation);
    } else {
        for (int choices = index; choices <= end; ++choices) {

            std::swap(permutation[index], permutation[choices]);
            permutationHelper(permutation, index + 1, end, validPermutations);
            std::swap(permutation[index], permutation[choices]);
        }
    }
}
