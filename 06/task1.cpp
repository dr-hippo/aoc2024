#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include "shared.h"
#include "aoccom.h"
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
    vector<pair<int, int>> dirs {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int guardDir = 0;
    pair<int, int> targetPos = {0, 0};
    set<pair<int, int>> visitedCoords;

    inputFile.open("input.txt");

    while (getline(inputFile, line)) {
        size_t guardXVal = line.find(guard);
        if (guardXVal != string::npos) guardPos = {guardXVal, lineIndex};
        grid.push_back(line);
        lineIndex++;
    }

    while (true) {
        visitedCoords.insert(guardPos);
        targetPos = {guardPos.first + dirs[guardDir].first, guardPos.second + dirs[guardDir].second};

        // If guard is about to move out of bounds, exit loop
        if (!aocc::isInBounds(grid, targetPos)) break;

        // If position in front is obstructed, turn right
        while (grid[targetPos.second][targetPos.first] == obstruction) {
            guardDir = (guardDir + 1) % 4;
            targetPos = {guardPos.first + dirs[guardDir].first, guardPos.second + dirs[guardDir].second};
        }

        // Move guard
        guardPos = targetPos;
    }

    // Display result
    cout << visitedCoords.size() << endl;

    inputFile.close();
    return 0;
}
