// Common utility functions
#include <string>
#include <vector>
#include "aoccom.h"

namespace aocc {
    int signum(int value) {
        return (value > 0) - (value < 0);
    }

    std::vector<int> splitToInts(std::string s, std::string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        std::vector<int> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(stoi(token));
        }

        res.push_back(stoi(s.substr(pos_start)));
        return res;
    }

    bool isInBounds(std::vector<std::string> grid, int x, int y) {
        return x >= 0 && y >= 0 && x < (int)grid[0].size() && y < (int)grid.size();
    }
}
