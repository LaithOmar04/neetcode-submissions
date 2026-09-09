/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) { return nullptr; }

        int size = 0;
        ListNode* cur = head;
        while(cur) {
            ++size;
            cur = cur->next;
        }

        int nodeIdx = size - n;
        ListNode* prev = nullptr;
        cur = head;

        int curIdx = 0;
        while(curIdx != nodeIdx) {
            prev = cur;
            cur = cur->next;
            ++curIdx;
        }

        if(!prev) {
            return cur->next;
        }

        prev->next = cur->next;
        return head;
    }
};
