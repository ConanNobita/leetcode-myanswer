#include "common.h"

USESTD

class Solution {
public:
    string reverseStr(string s, int k) {
        int two_k = k << 1, size = s.size();
        string out = string(size, '0');

        int count = size / two_k;
        for (int i = 0; i < count; i++) {
            int base = i * two_k;
            for (int j = 0; j < k; j++) {
                out[base + j] = s[base + k - 1 - j];
                out[base + k + j] = s[base + k + j];
            }
        }

        int remain = size - count * two_k;
        int base = size - remain;
        if (remain >= k && remain < two_k) { 
            for (int i = 0; i < k; i++) {
                out[base + i] = s[base + k - i - 1];
            }

            remain -= k;
            for (int i = 0; i < remain; i++) {
                int index = base + k + i;
                out[index] = s[index];
            }
        } else if (remain < k) {
            for (int i = 0; i < remain; i++) {
                out[base + i] = s[base + remain - 1 - i];
            }
        } 

        return out;
    }
};
