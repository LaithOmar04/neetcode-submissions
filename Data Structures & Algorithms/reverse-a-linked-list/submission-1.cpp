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
    ListNode* reverseList(ListNode* head) {
        //<1 2->3->4->5->
        // t->
        // 1->2->
        if(head == nullptr) { return nullptr; }
        if(head->next == nullptr) { return head; }
        if(head->next->next == nullptr) {
            ListNode* tmp = head->next;
            head->next = nullptr;
            tmp->next = head;
            return tmp;
        }
        // 1->2->
        ListNode* cur = head;
        ListNode* tmp = cur->next;
        bool start = true;
        while(tmp->next != nullptr) {
            if(start) {
                cur->next = nullptr;
                start = false;
                continue;
            }

            ListNode* next = tmp->next;
            tmp->next = cur;
            cur = tmp;
            tmp = next;
        }

        tmp->next = cur;
        return tmp;
    }
};
