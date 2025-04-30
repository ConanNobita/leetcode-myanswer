#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode temp(0, head);
        ListNode* node = head;
        ListNode* prev = &temp;

        while (node != nullptr && node->next != nullptr) {
            ListNode* next = node->next;
            ListNode* next1 = next->next;

            prev->next = next;
            node->next = next1;
            next->next = node;

            prev = node;
            node = next1;
        }

        return temp.next;
    }
};
    