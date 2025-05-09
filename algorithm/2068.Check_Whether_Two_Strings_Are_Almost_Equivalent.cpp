#include "common.h"

USESTD

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int word1Chars[26] = { 0 };
        int word2Chars[26] = { 0 };

        for (int i = 0, size1 = word1.size(); i < size1; i++) {
            char ch = word1[i];
            word1Chars[(ch - 'a')]++;
        }

        for (int i = 0, size2 = word2.size(); i < size2; i++) {
            char ch = word2[i];
            word2Chars[(ch - 'a')]++;
        }

        for (int i = 0; i < 26; i++) {
            int diff = word1Chars[i] - word2Chars[i];
            if (diff < -3 || diff > 3) {
                return false;
            }
        } 

        return true;
    }
};