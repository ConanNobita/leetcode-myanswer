#include "common.h"

USESTD 

class Solution {
public:
    bool isThree(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (i * i == n) {
                return true;
            }

            if (n % i == 0) {
                return false;
            }
        }

        return false;
    }
};