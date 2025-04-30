#include "common.h"
#include "Node.h"

USESTD

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (node == nullptr) {
            return false;
        }
           
        int value
        queue<TreeNode *> q;
        TreeNode *node = root;
        q.push(node);

        while (!q.empty()) {
            node = q.front();
            q.pop();
            
            if (node->left) {
                if (node->left->val >= node->val)
                    return false;
                q.push(node->left);
            }
            
            if (node->right) {
                if (node->right->val <= node->val)
                    return false;
                q.push(node->right);
            }
        }
        
        return true;
    }
};