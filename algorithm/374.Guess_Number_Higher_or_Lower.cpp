#include "common.h"

USESTD;

class Solution {
public:
    int guessNumber(int n) {
        if (guess(n) == 0) return n;
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2, t = guess(mid);
            if (t == 0) return mid;
            else if (t == 1) left = mid;
            else right = mid;
        }
        return left;
    }
};