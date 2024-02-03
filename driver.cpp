//
// Created by Paolo Lanaro on 1/27/2024.
//

#include <iostream>
#include <vector>
#include <string>
#include "./lib/include/MergeSortString.h"
#include "./lib/include/Permutation.h"

using std::string;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Did not run program with only one argument." << endl;
    }
    string origin = argv[1];
    cout << "Pre sort: " << origin << endl;
    string sorted = MergeSortString::lexicographicSort(origin);
    cout << "After sort: " << sorted << endl;

    vector<string> permutations = Permutation::getPermutations("aadit");

    for (int i = 0; i < permutations.size(); ++i) {
        cout << "Permutation " << i << ": " << permutations[i] << endl;
    }

}
