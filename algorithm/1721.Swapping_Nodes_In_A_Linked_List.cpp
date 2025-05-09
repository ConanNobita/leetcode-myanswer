#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }

        int front = 0, back = 0;
        ListNode* kNode = nullptr;
        ListNode* kNodePrev = nullptr;
        ListNode* lastKNode = nullptr;
        ListNode* lastKNodePrev = nullptr;

        ListNode newHead(0, head);
        visitNode(head, &kNodePrev, &kNode, &lastKNodePrev, &lastKNode, front, back, k);

        if (kNode == lastKNode) {
            return newHead.next;
        }

        ListNode* next0 = kNode->next;
        ListNode* next1 = lastKNode->next;

        if (kNode != next1 && lastKNode != next0) {
            kNode->next = next1;
            lastKNode->next = next0;

            if (kNodePrev != nullptr) {
                kNodePrev->next = lastKNode;
            } else {
                newHead.next = lastKNode;
            }

            if (lastKNodePrev != nullptr) {
                lastKNodePrev->next = kNode;
            } else {
                newHead.next = kNode;
            }
        } else if (kNode != next1 && lastKNode == next0) {
            kNode->next = next1;
            lastKNode->next = kNode;
            
            if (kNodePrev != nullptr) {
                kNodePrev->next = lastKNode;
            } else {
                newHead.next = lastKNode;
            }

        } else if (kNode == next1 && lastKNode != next0) {
            kNode->next = lastKNode;
            lastKNode->next = next0;

            if (lastKNodePrev != nullptr) {
                lastKNodePrev->next = kNode;
            } else {
                newHead.next = kNode;
            }
        }

        return newHead.next;
    }

private:
    void visitNode(ListNode* node, ListNode** kNodePrev, ListNode** kNode, ListNode** lastKNodePrev, ListNode** lastKNode, int& front, int& back, int k) {
        if (++front == k) {
            *kNode = node;
        }

        if (front + 1 == k) {
            *kNodePrev = node;
        }

        if (node->next == nullptr) {
            if (++back == k) {
                *lastKNode = node;
            }
            
            return;
        }

		visitNode(node->next, kNodePrev, kNode, lastKNodePrev, lastKNode, front, back, k); 
        if (++back == k) {
            *lastKNode = node;
        }

        if (back - 1 == k) {
            *lastKNodePrev = node;
        }
    }
};