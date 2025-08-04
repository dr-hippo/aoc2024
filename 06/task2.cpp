#include <iostream>
#include <fstream>
#include "shared.h"
using namespace std;

int main() {
    // Initialize variables
    ifstream inputFile;
    string line;

    inputFile.open("input.txt");

    while (getline(inputFile, line)) {

    }

    // Display result
    cout << "Hello World 2! " << xkcdRand() << endl;

    inputFile.close();
    return 0;
}
