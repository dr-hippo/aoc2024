#include <iostream>
#include <fstream>
#include <vector>
using namespace std; 

// Returns whether a sequence of characters on the grid, starting from (posX, posY) and spaced by (deltaX, deltaY), matches query
bool searchInGrid(string query, vector<string> grid, int posX, int posY, int deltaX, int deltaY) {
    return true;
}

int main() {
    // Initialize variables
    ifstream inputFile;
    string line;
    vector<string> grid;
    const string searchString = "XMAS";

    inputFile.open("input.txt");

    while (getline(inputFile, line)) {
        grid.push_back(line);
    }

    cout << grid[9][2] << endl;

    inputFile.close();
    return 0;
}
