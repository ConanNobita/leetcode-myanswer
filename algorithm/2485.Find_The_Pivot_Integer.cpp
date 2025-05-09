#include "common.h"

USESTD 

class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        vector<int> array(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            sum += i;
            array[i] = sum;
        }

        for (int i = 1; i <= n; i++) {
            if (array[i - 1] == sum - array[i]) {
                return i;
            }
        }

        return -1;
    }
};