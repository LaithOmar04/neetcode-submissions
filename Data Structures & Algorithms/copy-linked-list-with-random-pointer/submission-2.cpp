/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return nullptr;
        }

        unordered_map<Node*, int> nodeIdx;
        unordered_map<int, Node*> nodes;

        Node* newHead = new Node(0);
        Node* newCur = newHead;
        Node* cur = head;
        
        int idx = 0;

        while(cur) {
            newCur->val = cur->val;
            if(!cur->next) {
                newCur->next = nullptr;
            } else {
                Node* nextNode = new Node(0);
                newCur->next = nextNode;
            }

            nodeIdx[cur] = idx;
            nodes[idx] = newCur;

            newCur = newCur->next;
            cur = cur->next;
            ++idx;
        }

        newCur = newHead;
        cur = head;
        while(newCur) {
            if(cur->random) {
               int randIdx = nodeIdx[cur->random]; 
               newCur->random = nodes[randIdx];
            }

            newCur = newCur->next;
            cur = cur->next;
        }

        return newHead;
    }
};
