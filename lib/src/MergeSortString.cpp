//
// Created by Paolo Lanaro on 1/28/2024.
//
#include "../include/MergeSortString.h"

#include <sstream>
#include <cmath>

using std::string;

string MergeSortString::lexicographicSort(const string& word) {
    return mergesort(word);
}

string MergeSortString::merge(const string& left, const string& right) {
    int n = left.length() + right.length();
    std::stringstream result;
    int j = 0, k = 0;

    for (int i = 0; i < n; ++i) {
        if (j >= left.length()) {
            result << right[k];
            ++k;
        } else if (k >= right.length()) {
            result << left[j];
            ++j;
        } else if (left[j] <= right[k]) {
            result << left[j];
            j++;
        } else {
            result << right[k];
            k++;
        }
    }

    return result.str();
}

string MergeSortString::mergesort(const string& word) {
    if (word.length() == 1) {
        return word;
    }

    int midPoint = ceil((double) word.length() / 2);
    string left = mergesort(word.substr(0, midPoint));
    string right = mergesort(word.substr(midPoint, word.length() - midPoint));

    string result = merge(left, right);

    return result;
}

