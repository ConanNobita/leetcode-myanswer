#include "common.h"

USESTD

class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        while (mask < n) {
            mask = (mask << 1) | 0x1;
        }

        return n ^ mask;
    }
};
