#include "common.h"
#include "node.h"

USESTD 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) {
            return result;
        }

        string parenthesis = "";
        generate(result, parenthesis, n, n);
        return result;
    }

private:
    void generate(vector<string>& result, string& parenthesis, int remainLeft, int remainRight) {
        if (remainLeft > 0 && remainRight > 0) {
            string parenthesisLeft = parenthesis + '(';
            generate(result, parenthesisLeft, remainLeft - 1, remainRight);

            if (parenthesis.size() > 0 && remainRight > remainLeft) {
                string parenthesisRight = parenthesis + ')';
                generate(result, parenthesisRight, remainLeft, remainRight - 1);
            }

        } else if (remainLeft == 0 && remainRight > 0) {
            string parenthesisRight = parenthesis + ')';
            generate(result, parenthesisRight, 0, remainRight - 1);
        } else if (remainLeft == 0 && remainRight == 0) {
            result.push_back(parenthesis);
            return;
        }
    }
};