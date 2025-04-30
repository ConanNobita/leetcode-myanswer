#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    // recur
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        dfs(root, result);
        return result;
    }

/*
	vector<int> preorder(Node* root) {
		vector<int> result;
		if (root == nullptr) {
			return result;
		}

		Node* node = root;
		stack<Node*> nodeStack;
		
		while (node != nullptr || !nodeStack.empty()) {
			if (node != nullptr) {
				vector<Node*>& children = node->children;
				result.push_back(node->val);

				int childCount = children.size();
				for (int i = childCount - 1; i >= 0; --i) {
					nodeStack.push(children[i]);
				}
			}
			
			if (nodeStack.empty()) {
				break;
			}

			node = nodeStack.top();
			nodeStack.pop();
		}

		return result;
	}
*/

private:
    void dfs(Node* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        vector<Node*>& children = node->children;
        result.push_back(node->val);
        
        for (Node* child : children) {
            dfs(child, result);
        }
    }
};
    