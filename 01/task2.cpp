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
    int similarityScoreSum = 0;

    inputFile.open("input.txt");

    // Read input file; parse each line and put numbers into two arrays
    while (getline(inputFile, line)) {
        sscanf(&(line[0]), "%d   %d", &(left[lineNumber]), &(right[lineNumber]));
        lineNumber++;
    }
    
    // Sort second array
    sort(right, right + sizeof(right)/sizeof(right[0]));

    // Loop through first array; calculate similarity score for each value
    for (int i = 0; i < 1000; i++) {
        int similarityScore = 0;
        int value = left[i];

        for (int j = 0; j < 1000; j++) {
            if (right[j] > value) {
                break;
            }

            else if (right[j] == value)
            {
                similarityScore += value; 
            }
        }

        similarityScoreSum += similarityScore;
    }

    // Display result
    cout << similarityScoreSum << endl;

    inputFile.close();
    return 0;
}
