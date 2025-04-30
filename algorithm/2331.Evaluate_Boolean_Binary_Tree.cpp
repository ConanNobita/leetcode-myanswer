#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        return evaluate(root);
    }

private:
    bool evaluate(TreeNode* node) {
        if (node->left == nullptr && node->right == nullptr) {
            return node->val == 1;
        } else if (node->left == nullptr && node->right != nullptr) {
            return node->val == 2 ? evaluate(node->right) : 0;
        } else if (node->left != nullptr && node->right == nullptr) {
            return node->val == 2 ? evaluate(node->left) : 0;
        } else {
            int left = evaluate(node->left);
            int right = evaluate(node->right);
            return node->val == 2 ? (left || right) : (left && right);
        }
    }
};