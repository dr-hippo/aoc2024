#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "aoccom.h"
using namespace std;

// Report checking function that takes a sequence of integers
int checkReportSafe(vector<int> report) {
    int previousValue, currentValue, difference;
    int sign = aocc::signum(report[1] - report[0]);

    for (size_t i = 1; i < report.size(); i++) {
        previousValue = report[i - 1];
        currentValue = report[i];
        difference = currentValue - previousValue;

        if (abs(difference) < 1
            || abs(difference) > 3
            || aocc::signum(difference) != sign)
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
        safeReportCount += checkReportSafe(aocc::splitToInts(line, " "));
    }

    // Display result
    cout << safeReportCount << endl;

    inputFile.close();
    return 0;
}