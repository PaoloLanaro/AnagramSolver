//
// Created by lanaro on 1/27/2024.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Did not run program with only one argument." << endl;
    }
    string origin = argv[1];
    cout << "Pre sort: " << origin << endl;
    std::sort(origin.begin(), origin.end());
    cout << "After sort: " << origin << endl;


}
