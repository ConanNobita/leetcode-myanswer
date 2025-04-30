#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        dfs(root, result);
        return result;
    }

private:
    void dfs(Node* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        vector<Node*>& children = node->children;
        for (Node* child : children) {
            dfs(child, result);
        }

        result.push_back(node->val);
    }
};
    