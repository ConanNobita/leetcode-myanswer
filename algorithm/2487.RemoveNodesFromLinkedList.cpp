#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
	ListNode* removeNodes(ListNode* head) {
		ListNode** removedNodes = nullptr;
		ListNode** currentNode = nullptr;

		removeNode(head, removedNodes, currentNode);
		return *removedNodes;
	}

	void removeNode(ListNode* node, ListNode** removedNodes, ListNode** currentNode) {
		if (node == nullptr) {
			return;
		}

		ListNode* next = node->next;
		if (next == nullptr) {
			return;
		}

		if (next->val > node->val) {
			if (*removedNodes == nullptr) {
				*removedNodes = next;
				*currentNode = next;
			}
			else {
				(*currentNode)->next = next;
			}

			node->next = next->next;
		}

		removeNode(node->next, removedNodes, currentNode);
	}
};