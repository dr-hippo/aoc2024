#ifndef AOCCOM_H
#define AOCCOM_H

#include <string>
#include <vector>

namespace aocc {

    int signum(int value);

    std::vector<int> splitToInts(std::string s, std::string delimiter);

    bool isInBounds(std::vector<std::string> grid, int x, int y);
}

#endif
