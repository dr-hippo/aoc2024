#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Initialize variables
    ifstream inputFile;
    int left[1000];
    int right[1000];
    string line;
    string left_str;
    string right_str;
    int lineNumber = 0;
    int pairDistance = 0;
    int distanceSum = 0;

    inputFile.open("input.txt");

    // Read file contents; parse each line and put numbers into two arrays
    while (getline(inputFile, line)) {
        left_str = line.substr(0, 5);
        right_str = line.substr(8, 5);

        left[lineNumber] = stoi(left_str);
        right[lineNumber] = stoi(right_str);

        lineNumber++;
    }

    // Sort arrays
    sort(left, left + sizeof(left)/sizeof(left[0]));
    sort(right, right + sizeof(right)/sizeof(right[0]));

    // Loop through arrays; calculate distance between values in each pair and sum them
    for (int i = 0; i < 1000; i++) {
        pairDistance = abs(left[i] - right[i]);
        distanceSum += pairDistance;
    }

    cout << distanceSum;

    inputFile.close();
    return 0;
}
