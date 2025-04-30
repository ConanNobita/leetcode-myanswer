#include "common.h"

USESTD 

static string Charaters[] = {
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz",
};

class Solution {
public:
    vector<string> letterCombinations(string digits) { 
        vector<string> result;
        if (digits.size() > 0) {
            string empty = "";
            next(result, digits, empty, 0, digits.size());  
        }
    
        return result;
    }

private:
    void next(vector<string>& words, string& digits, string& word, int index, int number) {
        if (index == number) {
            words.push_back(word);
            return;
        }
        
        int nextIndex = index + 1;
        int digit = digits[index] - '0';
        string& digitChars = Charaters[digit];

        for (int i = 0; i < digitChars.size(); ++i) {
            string newWord = word + digitChars[i];
            next(words, digits, newWord, nextIndex, number);
        }
    }
};