#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    bool checkTree(TreeNode* root) {
		return check(root);
    }

private:
    bool check(TreeNode* node) {
        if (node != nullptr) {
            TreeNode* left = node->left;
			TreeNode* right = node->right;

            if (left == nullptr && right == nullptr) {
                return true;
            }

            int lvalue = left != nullptr ? left->val : 0;
			int rvalue = right != nullptr ? right->val : 0;
			if (lvalue + rvalue != node->val) {
				return false;
			}

			return check(left) && check(right);
        }

        return true;
    }
};