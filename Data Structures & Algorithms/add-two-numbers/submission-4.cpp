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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while(l1 && l2) {
            int curSum = l1->val + l2->val;
            int curVal = curSum % 10;
            if(carry) {
                curVal += carry;
                carry = 0;
            }
            if(curSum >= 10) {
                carry = curSum / 10;
            }
            
            ListNode* newNode = new ListNode(curVal);
            cur->next = newNode;
            cur = cur->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        //2222
        //22
        //4422
        //4422
        while(l1) {
            int curSum = l1->val + carry;
            if(carry) {
                carry = 0;
            }
            int curVal = curSum % 10;
            if(curSum >= 10) {
                carry = curSum / 10;
            }

            ListNode* newNode = new ListNode(curVal);
            cur->next = newNode;
            cur = cur->next;

            l1 = l1->next;
        }
        while(l2) {
            int curSum = l2->val + carry;
            if(carry) {
                carry = 0;
            }
            int curVal = curSum % 10;
            if(curSum >= 10) {
                carry = curSum / 10;
            }

            ListNode* newNode = new ListNode(curVal);
            cur->next = newNode;
            cur = cur->next;

            l2 = l2->next;
        }

        if(carry) {
            ListNode* newNode = new ListNode(carry);
            cur->next = newNode;
            cur = cur->next;
        }

        return dummy->next;
    }
};
