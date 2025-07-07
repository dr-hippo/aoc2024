#include <iostream>
#include <fstream>
#include <vector>
#include "aoccom.h"
using namespace std;

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

bool sequenceObeysRules(vector<int> sequence, vector<pair<int, int>> rules) {
    for (pair<int, int> rule: rules) {
        if (!sequenceObeysRule(sequence, rule)) { return false; }
    }

    return true;
}

// Keep swapping pairs of entries that violate a rule until the sequence obeys all rules
// Probably not the most efficient, but it works
vector<int> fixUpdates(vector<int> incorrectUpdates, vector<pair<int, int>> rules) {
    while (!sequenceObeysRules(incorrectUpdates, rules)) {
        for (size_t k = 0; k < rules.size(); k++) {
            int secondNumberIndex = -1;
            for (size_t l = 0; l < incorrectUpdates.size(); l++) {
                if (secondNumberIndex != -1 && incorrectUpdates[l] == rules[k].first) {
                    iter_swap(incorrectUpdates.begin() + l, incorrectUpdates.begin() + secondNumberIndex);
                    break;
                }

                if (incorrectUpdates[l] == rules[k].second) {
                    secondNumberIndex = l;
                }
            }
        }
    }

    return incorrectUpdates;
}

int main() {
    // Initialize variables
    ifstream inputFile;
    string line;
    bool isParsingRules = true;
    vector<pair<int, int>> rules;
    vector<vector<int>> incorrectUpdateSeqs;
    int correctedUpdateMiddleNumberSum = 0;

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
            if (!sequenceObeysRules(pageUpdates, rules)) incorrectUpdateSeqs.push_back(pageUpdates);
        }
    }

    // Fix incorrect updates and sum middle entries
    for (vector<int> updates: incorrectUpdateSeqs) {
        vector<int> correctedUpdates = fixUpdates(updates, rules);
        correctedUpdateMiddleNumberSum += correctedUpdates[(updates.size()-1)/2];
    }

    // Display result
    cout << correctedUpdateMiddleNumberSum << endl;

    inputFile.close();
    return 0;
}
