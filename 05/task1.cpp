#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Returns whether the numbers in the rule appear in the sequence in the same order, if both numbers appear; otherwise returns true.
int sequenceObeysRule(vector<int> sequence, pair<int, int> rule) {
    bool firstNumberOccurred = false;
    for (size_t i = 0; i < sequence.size(); i++) {
        if (sequence[i] == rule.first) {
            firstNumberOccurred = true;
            continue;
        }

        // If the second number occurs but the first number has not
        if (!firstNumberOccurred && sequence[i] == rule.second) {
            return 0;
        }
    }

    return 1;
}

int main() {
    // Initialize variables
    ifstream inputFile;
    string line;

    inputFile.open("input.txt");

    while (getline(inputFile, line)) {

    }

    // Display result
    cout << "Hello World!" << endl;

    inputFile.close();
    return 0;
}
