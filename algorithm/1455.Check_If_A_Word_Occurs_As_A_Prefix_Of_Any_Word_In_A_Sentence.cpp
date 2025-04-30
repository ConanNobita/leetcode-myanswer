#include "common.h"

USESTD

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int lastSpace = -1, spaceCount = 0;
        for (int i = 0; i <= sentence.size(); i++) {
            if (i == sentence.size() || sentence[i] == ' ') {
                bool findPrefix = true;
                int startIndex = lastSpace + 1;
                
                if (sentence[i] == ' ') {
                    spaceCount++;
                    lastSpace = i;
                }
                
                if (i - startIndex < searchWord.size()) {
                    findPrefix = false;
                    continue;
                }

                for (int j = 0; j < searchWord.size(); j++) {
                    if (sentence[startIndex + j] != searchWord[j]) {
                        findPrefix = false;
                        break;
                    }
                }

                if (findPrefix) {
                    return i < sentence.size() ? spaceCount : spaceCount + 1;
                }
            }
        }

        return -1;
    }
};