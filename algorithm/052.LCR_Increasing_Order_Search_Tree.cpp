#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
	TreeNode* increasingBST(TreeNode* root) {
		if (root == nullptr) {
			return nullptr;
		}

		int minValue = root->val;
		TreeNode* current = nullptr;
		TreeNode* minNode = nullptr;

		dfs(root, &current, &minNode, minValue);
		return minNode;
	}

private:
	void dfs(TreeNode* node, TreeNode** current, TreeNode** minNode, int& minValue) {
		if (node == nullptr) {
			return;
		}

		TreeNode* right = node->right;
		dfs(node->left, current, minNode, minValue);

		if (node->val <= minValue) {
			*minNode = node;
			minValue = node->val;
		}

		if (*current != nullptr) {
			(*current)->right = node;
		}

		node->left = nullptr;
		*current = node;
		dfs(right, current, minNode, minValue);
	}
};