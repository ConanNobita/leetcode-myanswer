#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    int countNodes(TreeNode* root) {
		int nodeCount = 0;
		dfs(root, nodeCount);
		return nodeCount;
    }

private:
	void dfs(TreeNode* node, int& nodeCount) {
		if (node != nullptr) {
			nodeCount++;
			dfs(node->left, nodeCount);
			dfs(node->right, nodeCount);
		}
	}
};