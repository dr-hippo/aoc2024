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
    int lineNumber = 0;
    int pairDistance = 0;
    int distanceSum = 0;

    inputFile.open("input.txt");

    // Read input file; parse each line and put numbers into two arrays
    while (getline(inputFile, line)) {
        sscanf(&(line[0]), "%d   %d", &(left[lineNumber]), &(right[lineNumber]));
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

    // Display result
    cout << distanceSum << endl;

    inputFile.close();
    return 0;
}
