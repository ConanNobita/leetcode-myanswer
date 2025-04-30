#include "common.h"
#include "node.h"

USESTD

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* newHead = nullptr;
            reverse(head, &newHead);
            return newHead;
        }
    
    private:
        ListNode* reverse(ListNode* node, ListNode** head) {
            if (node == nullptr) {
                return nullptr;
            }
            
            ListNode* prev = reverse(node->next, head);
            if (prev == nullptr) {
                *head = node;
            }
            else {
                prev->next = node;
                node->next = nullptr;
            }
    
            return node;
        }
    };