#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Initialize variables
    ifstream inputFile;
    string line;

    inputFile.open("input.txt");

    while (getline(inputFile, line)) {

    }

    cout << "Hello World 2!" << endl;

    inputFile.close();
    return 0;
}
