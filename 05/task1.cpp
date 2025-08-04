#include <iostream>
#include <fstream>
#include <vector>
#include "aoccom.h"
using namespace std;

// Returns whether the numbers in the rule appear in the sequence in the same order, if both numbers appear; otherwise returns true.
bool sequenceObeysRule(vector<int> sequence, pair<int, int> rule) {
    bool secondNumberAppeared = false;
    for (size_t i = 0; i < sequence.size(); i++) {
        // Sequence does not obey rule if the first number appears after the second one
        if (secondNumberAppeared && sequence[i] == rule.first) {
            return false;
        }

        if (sequence[i] == rule.second) {
            secondNumberAppeared = true;
        }
    }

    return true;
}

int main() {
    // Initialize variables
    ifstream inputFile;
    string line;
    vector<pair<int, int>> rules;
    bool isParsingRules = true;
    int correctUpdateMiddleNumberSum = 0;

    inputFile.open("input.txt");

    while (getline(inputFile, line)) {
        if (line.size() == 0) {
            isParsingRules = false;
            continue;
        }

        // Parse and store ordering rules
        if (isParsingRules) {
            size_t delimPos = line.find('|');
            // Split line by delimiter (pipe character)
            auto rule = make_pair(
                stoi(line.substr(0, delimPos)),
                stoi(line.substr(delimPos+1, line.size() - delimPos))
            );
            rules.push_back(rule);
        }

        // Lists of pages needing update comes after blank line
        else {
            vector<int> pageUpdates = aocc::splitToInts(line, ",");
            bool updateObeysAllRules = true;
            for (size_t j = 0; j < rules.size(); j++) {
                if (!sequenceObeysRule(pageUpdates, rules[j])) {
                    updateObeysAllRules = false;
                    break;
                }
            }

            correctUpdateMiddleNumberSum += updateObeysAllRules ? pageUpdates[(pageUpdates.size()-1)/2] : 0;
        }
    }

    // Display result
    cout << correctUpdateMiddleNumberSum << endl;

    inputFile.close();
    return 0;
}
