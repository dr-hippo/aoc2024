#include <iostream>
#include <fstream>
#include <vector>
#include "shared.h"
using namespace std;

int main() {
    // Initialize variables
    ifstream inputFile;
    string line;
    vector<string> grid;
    char freeSpace = '.';
    char guard = '^';

    inputFile.open("input.txt");

    while (getline(inputFile, line)) {
        grid.push_back(line);
    }

    for(const auto& s: grid) cout << s << endl;
    
    // Display result
    cout << "Hello World! " << xkcdRand() << endl;

    inputFile.close();
    return 0;
}
