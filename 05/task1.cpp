#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// TODO: Refactor this function into source file containing common functions, per DRY
vector<int> splitToInts(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<int> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(stoi(token));
    }

    res.push_back(stoi(s.substr(pos_start)));
    return res;
}

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
            vector<int> pageUpdates = splitToInts(line, ",");
            bool updateObeysAllRules = true;
            for (size_t j = 0; j < rules.size(); j++) {
                if (!sequenceObeysRule(pageUpdates, rules[j])) {
                    cout << line << " " << rules[j].first << "|" << rules[j].second << endl;
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
