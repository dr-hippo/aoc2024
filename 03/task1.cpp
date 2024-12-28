#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <fstream>
using namespace std;
 
int main() {
    // Initialize variables
    ifstream inputFile;
    string line;
    regex instructionRegex(R"(mul\((\d+),(\d+)\))");
    int productSum = 0;

    inputFile.open("input.txt");

    // Read input file; search each line for multiplication instructions and add together products
    while (getline(inputFile, line)) {
        auto instructionsBegin = sregex_iterator(line.begin(), line.end(), instructionRegex);
        auto instructionsEnd = sregex_iterator();
        
        for (auto i = instructionsBegin; i != instructionsEnd; ++i) {
            smatch match = *i;
            int product = stoi(match[1]) * stoi(match[2]);
            productSum += product;
        }
    }

    // Display result
    cout << productSum << endl;

    inputFile.close();
    return 0;
}