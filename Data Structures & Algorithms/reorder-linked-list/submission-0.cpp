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
    void reorderList(ListNode* head) {
        if(!head || !head->next) {
            return;
        }

        auto* slow = head;
        auto* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHead = reverseList(slow->next);
        slow->next = nullptr;
        ListNode* cur = head;

        ListNode dummy(0);
        ListNode* newHead = &dummy;
        ListNode* newCur = newHead;
        bool first = true;
        bool firstHalf = false;
        while(cur && secondHead) {
            if(first) {
                newCur->next =  cur;
                cur = cur->next;
                newCur = newCur->next;
                first = false;
                continue;
            }
            if(firstHalf) {
                newCur->next = cur;
                cur = cur->next;
            } else {
                newCur->next = secondHead;
                secondHead = secondHead->next;
            }
            
            firstHalf = !firstHalf;
            newCur = newCur->next;
        }

        if(cur) {
            newCur->next = cur;
        } else if(secondHead) {
            newCur->next = secondHead;
        }

        head = newHead->next;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};
