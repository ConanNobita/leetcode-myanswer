#include "common.h"

USESTD

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int count = 0, size = s.size();
        for (int i = 0; i < size; i++) {
            count = s[i] == '-' ? count : count + 1; 
        }

        int groups = count / k, first = count % k, index = 0, index2 = 0;
        string output(first == 0 ? count + groups - 1 : count + groups, '0');

        for (int i = 0; i < size; i++) {
            if (s[i] != '-') {
                output[index++] = toupper(s[i]);
                index2++;

                if (index2 > first) {
                   if (index2 % k == first) {
                       output[index++] = '-';
                   }
                } else {
                    if (first > 0 && index2 == first) {
                        output[index++] = '-';
                    }
                }  
            }
        }

        return output;
    }
};

int main(int argc, char *argv[]) {
    string str = argv[1];
    Solution solution;
    string output = solution.licenseKeyFormatting(str, atoi(argv[2]));
    cout << output << endl;
}