#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            if ((i & 1) == 1) {
                result[i] = result[i >> 1] + 1;
            } else {
                result[i] = result[i >> 1];
            }
        }

        return result;
    }
};