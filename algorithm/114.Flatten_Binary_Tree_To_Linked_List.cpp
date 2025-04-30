#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		TreeNode* parent = nullptr;
		dfs(root, &parent);
	}

private:
	void dfs(TreeNode* node, TreeNode** current) {
		if (node == nullptr) {
			return;
		}

		TreeNode* left = node->left;
		TreeNode* right = node->right;

		if (*current != nullptr) {
			(*current)->left = nullptr;
			(*current)->right = node;
		}

		*current = node;
		dfs(left, current);
		dfs(right, current);
	}
};