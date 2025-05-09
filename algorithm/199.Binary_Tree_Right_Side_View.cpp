#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        
        int count = 1, nextCount = 0;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            for (int i = 0, end = count - 1; i < end; i++) {
                TreeNode* node = nodeQueue.front();
                if (node->left != nullptr) {
                    nodeQueue.push(node->left);
                    nextCount++;
                }

                if (node->right != nullptr) {
                    nodeQueue.push(node->right);
                    nextCount++;
                }

                nodeQueue.pop();
            }
            
            TreeNode* node = nodeQueue.front();
            if (node->left != nullptr) {
                nodeQueue.push(node->left);
                nextCount++;
            }

            if (node->right != nullptr) {
                nodeQueue.push(node->right);
                nextCount++;
            }

            result.push_back(node->val);
            nodeQueue.pop();

            count = nextCount;
            nextCount = 0;
        }

        return result;
    }
};