#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int signum(int value) {
    return (value > 0) - (value < 0);
}

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

// Report checking function that takes a sequence of integers
int checkReportSafe(vector<int> report) {
    int previousValue, currentValue, difference;
    int sign = signum(report[1] - report[0]);

    for (size_t i = 1; i < report.size(); i++) {
        previousValue = report[i - 1];
        currentValue = report[i];
        difference = currentValue - previousValue;

        if (abs(difference) < 1
            || abs(difference) > 3
            || signum(difference) != sign)
        {
            return 0;
        }
    }

    return 1;
}

int main() {
    // Initialize variables
    ifstream inputFile;
    string line;
    int safeReportCount = 0;

    inputFile.open("input.txt");

    // Read input file; split each line into sequence of integers and check if safe
    while (getline(inputFile, line)) {
        safeReportCount += checkReportSafe(splitToInts(line, " "));
    }

    // Display result
    cout << safeReportCount << endl;

    inputFile.close();
    return 0;
}