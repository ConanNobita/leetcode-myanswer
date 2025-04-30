#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }

        int back = 0, count = 0;
        ListNode* node = head, *kNode = nullptr, *lNode = nullptr;

        while (node != nullptr) {
            node = node->next;
            count++;
        }

        rotate(head, &kNode, &lNode, back, k % count);
        if (kNode != nullptr) {
            ListNode* next = kNode->next;
            kNode->next = nullptr;
            lNode->next = head;
            return next;
        }
        
        return head;
    }

private:
    void rotate(ListNode* node, ListNode** kNodePtr, ListNode** lastNodePtr, int& back, int k) {
        if (node->next == nullptr) {
            *lastNodePtr = node;
            return;
        }else {
            rotate(node->next, kNodePtr, lastNodePtr, back, k);
            if (*kNodePtr == nullptr && ++back == k) {
                *kNodePtr = node;
                return;
            }
        }
    }
};