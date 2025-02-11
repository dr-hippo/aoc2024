#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <fstream>
using namespace std;

void appendFoundIndexes(string s, regex rgx, vector<int>* vec) {
    for (auto i = sregex_iterator(s.begin(), s.end(), rgx); i != sregex_iterator(); ++i) {
        vec->push_back(i->position());
    }
}

int maxBelowValue(vector<int> vec, int val) {
    int result = -1;
    for (int i = 0; i < (int)vec.size(); i++) {
        if (vec[i] < val && vec[i] > result) {
            result = vec[i];
        }
    }
    return result;
}

int main() {
    // Initialize variables
    ifstream inputFile;
    string line;
    string fileContents;
    regex instructionRegex(R"(mul\((\d+),(\d+)\))");
    regex doRegex(R"(do\(\))");
    regex dontRegex(R"(don\'t\(\))");
    vector<int> doIndexes;
    vector<int> dontIndexes;
    int productSum = 0;

    inputFile.open("input.txt");

    // Read file contents
    while (getline(inputFile, line)) {
        fileContents += line;
    }

    // Cache indexes of do()/don't() instructions
    appendFoundIndexes(fileContents, doRegex, &doIndexes);
    appendFoundIndexes(fileContents, dontRegex, &dontIndexes);

    // Find and conditionally execute mult instructions
    auto instructionsBegin = sregex_iterator(fileContents.begin(), fileContents.end(), instructionRegex);
    auto instructionsEnd = sregex_iterator();

    for (auto i = instructionsBegin; i != instructionsEnd; ++i) {
        smatch match = *i;
        int lastDoIndex = maxBelowValue(doIndexes, match.position());
        int lastDontIndex = maxBelowValue(dontIndexes, match.position());
        // Check if the previous do() is closer to the mult instruction than the previous don't() 
        // When there are no do/don'ts before it, both maxBelowValue calls return -1
        // This means that the multiplication will be executed, as specified
        if (lastDoIndex >= lastDontIndex) {
            int product = stoi(match[1]) * stoi(match[2]);
            productSum += product;
        }
    }

    // Display result
    cout << productSum << endl;

    inputFile.close();
    return 0;
}