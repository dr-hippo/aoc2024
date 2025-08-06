#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include "shared.h"
using namespace std;

int main() {
    // Initialize variables
    ifstream inputFile;
    string line;
    vector<string> grid;
    char obstruction = '#';
    char guard = '^';
    int lineIndex = 0;
    pair<int, int> guardPos = {0, 0};

    inputFile.open("input.txt");

    while (getline(inputFile, line)) {
        size_t guardXVal = line.find(guard);
        if (guardXVal != string::npos) guardPos = {guardXVal, lineIndex};
        grid.push_back(line);
        lineIndex++;
    }
    
    // Display result
    cout << "Hello World! " << guardPos.first << " " << guardPos.second << endl;

    inputFile.close();
    return 0;
}
