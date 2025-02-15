#include <iostream>
#include <fstream>
#include <vector>
using namespace std; 

bool isInBounds(vector<string> grid, int x, int y) {
    return x >= 0 && y >= 0 && x < (int)grid[0].size() && y < (int)grid.size();
}

// Checks if a sequence of characters on grid, starting from (posX, posY) and spaced by (deltaX, deltaY), matches query
int searchInGrid(string query, vector<string> grid, int posX, int posY, int deltaX, int deltaY) {
    for (size_t i = 0; i < query.size(); i++) {
        int currentX = posX + i * deltaX;
        int currentY = posY + i * deltaY;

        if (!isInBounds(grid, currentX, currentY)) {
            return 0;
        }

        if (grid[currentY][currentX] != query[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    // Initialize variables
    ifstream inputFile;
    string line;
    vector<string> grid;
    const string searchString = "XMAS";
    const int a[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int stringsFound = 0;

    inputFile.open("input.txt");

    while (getline(inputFile, line)) {
        grid.push_back(line);
    }

    // Loop through each character on grid
    for (size_t y = 0; y < grid.size(); y++) {
        for (size_t x = 0; x < grid[0].size(); x++) {
            // If the character matches the first character of the string to search for
            if (grid[y][x] == searchString[0]) {
                // Search in all 8 directions
                for (int i = 0; i < 8; i++) {
                    int deltaX = a[i];
                    int deltaY = a[(i+2)%8];
                    stringsFound += searchInGrid(searchString, grid, x, y, deltaX, deltaY);
                }
            }
        }
    }

    // Display result
    cout << stringsFound << endl;

    inputFile.close();
    return 0;
}
