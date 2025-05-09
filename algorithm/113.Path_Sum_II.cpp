#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        vector<int> tempArray;
        trace(result, tempArray, root, 0, targetSum);
        return result;
    }

private:
    void trace(vector<vector<int>>& result, vector<int>& tempArray, TreeNode* node, int sum, int targetSum) {
        if (node == nullptr) {
            return;
        }

        int newSum = sum + node->val;
        tempArray.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr) {    
            if (newSum == targetSum) {
                result.push_back(vector<int>(tempArray));
                tempArray.pop_back();
            }

            return;
        } 

        trace(result, tempArray, node->left, newSum, targetSum);
        trace(result, tempArray, node->right, newSum, targetSum);
        tempArray.pop_back();
    }
};