#include "common.h"

USESTD 

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int size = grid.size(), end = size - 1;

        for (int i = 0; i < size; i++) {
            vector<int>& rows = grid[i];
            for (int j = 0; j < size; j++) {
                if ((i == j || (i + j == end)) && rows[j] == 0) {
                    return false;
                }

                if ((i != j && (i + j != end)) && rows[j] != 0) {
                    return false;
                }
            }
        }

        return true;
    }
};