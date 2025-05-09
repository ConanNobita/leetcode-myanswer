#include "common.h"
#include "Node.h"

USESTD

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        bool valid = true;

        bfs(root, prev, valid);
        return valid;
    }

private:
    void bfs(TreeNode* node, long& prev, bool& valid) {
        if (valid && node != nullptr) {
            bfs(node->left, prev, valid);
            if (!valid) {
                return;
            }

            valid = node->val > prev;
            prev = node->val;
            bfs(node->right, prev, valid);
            
            if (!valid) {
                return;
            }
        }
    }
};
    