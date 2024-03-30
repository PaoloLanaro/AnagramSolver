//
// Created by Paolo Lanaro on 1/28/2024.
//

#include <algorithm>
#include "../include/Permutation.h"
#include "../include/MergeSortString.h"

using std::string;
using std::vector;
using std::unordered_set;

// temp set to avoid duplicates: "hello" will produce "ehllo" and "ehllo" as different permutations.
unordered_set<string> Permutation::fullPermutations;
// temp set to avoid duplicates: "hello" will produce "ehlo" and "ehlo" as different sub permutations.
unordered_set<string> Permutation::substringPermutations;

vector<string> Permutation::getFullPermutations(const std::string &word) {
    string sorted = MergeSortString::lexicographicSort(word);
    fullPermutationsHelper(sorted, 0, sorted.size() - 1);

    vector<string> result; // convert set to a sort of "output container" of vector.
    for (const auto &permutation : fullPermutations) {
        result.push_back(permutation);
    }
    std::sort(result.begin(), result.end());
    return result;
}

void Permutation::fullPermutationsHelper(string &permutation, const int &index, const int &end) {
    if (index == end) {
        fullPermutations.insert(permutation);
    } else {
        for (int choices = index; choices <= end; ++choices) {

            std::swap(permutation[index], permutation[choices]);
            fullPermutationsHelper(permutation, index + 1, end);
            std::swap(permutation[index], permutation[choices]);
        }
    }
}

vector<string> Permutation::getSubstringPermutations(const string &word) {
    string sorted = MergeSortString::lexicographicSort(word);
    substringPermutations.insert(sorted);
    substringPermutationsHelper(sorted);

    vector<string> result; // convert set to a sort of "output container" of vector.
    for (const auto &permutation : substringPermutations) {
        result.push_back(permutation);
    }
    std::sort(result.begin(), result.end());
    return result;
}

void Permutation::substringPermutationsHelper(const string& permutation) {
    for (int i = 0; i < permutation.size(); ++i) {
        string copy = permutation;
        copy.erase(i, 1);
        if (!copy.empty()) {
            substringPermutations.insert(copy);
            substringPermutationsHelper(copy);
        }
    }
}
