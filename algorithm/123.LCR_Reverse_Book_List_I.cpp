#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    vector<int> reverseBookList(ListNode* head) {
        vector<int> result;
        reverse(head, result);
        return result;
    }

private:
    void reverse(ListNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        
        reverse(node->next, result);
        result.push_back(node->val);
    }
};