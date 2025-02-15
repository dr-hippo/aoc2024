#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool crossEquals(char lhs1, char lhs2, char rhs1, char rhs2) {
    return (lhs1 == rhs1 && lhs2 == rhs2) || (lhs1 == rhs2 && lhs2 == rhs1);
}

// Check if the diagonal neighbors of the character at (posX, posY) on grid are char1 and char2, with each diagonal containing both characters.
// i.e.
// 1 . 1      
// . + .
// 2 . 2 
// Does not do bounds-checking or validate the center character 
int isCrossValid(vector<string> grid, int posX, int posY, char char1, char char2) {
    int a[4] = { -1, -1, 1, 1 };
    char c[4];

    for (int i = 0; i < 4; i++) {
        int offsetX = a[i];
        int offsetY = a[(i+1)%4];
        c[i] = grid[posY + offsetY][posX + offsetX];
        // 0 . 3
        // . + .
        // 1 . 2
    }

    if (crossEquals(c[0], c[2], char1, char2) && crossEquals(c[1], c[3], char1, char2)) {
        return 1;
    }

    return 0;
}

int main() {
    // Initialize variables
    ifstream inputFile;
    string line;
    vector<string> grid;
    int crossesFound = 0;
    const string searchString = "MAS";  // Must be 3 characters long

    inputFile.open("input.txt");

    while (getline(inputFile, line)) {
        grid.push_back(line);
    }

    // Loop through each internal character on grid
    for (size_t y = 1; y < grid.size() - 1; y++) {
        for (size_t x = 1; x < grid[0].size() - 1; x++) {
            // If this character could be the center of the cross, do further checking
            if (grid[y][x] == searchString[1]) {
                crossesFound += isCrossValid(grid, x, y, searchString[0], searchString[2]);
            }
        }
    }

    // Display result
    cout << crossesFound << endl;

    inputFile.close();
    return 0;
}
