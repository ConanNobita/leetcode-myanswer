#include "common.h"
#incldue "node.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        findAndDeleteNode(root, key);
        return root;
    }

private:
    void findAndDeleteNode(TreeNode* parent, TreeNode *node, int key) {
        if (node == nullptr) {
            return;
        }

        if (node->val == key) {
            
            return;
        }

        findAndDeleteNode(node, node->left, key);
        findAndDeleteNode(node, node->right, key);
    }
};

