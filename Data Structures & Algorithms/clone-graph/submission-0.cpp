/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        
        unordered_map<int, Node*> newNodes;
        queue<Node*> q;

        Node* head = new Node(node->val);
        newNodes[head->val] = head;
        q.push(node);

        while(!q.empty()) {
            Node* curNode = q.front();
            q.pop();
            Node* newNode = newNodes[curNode->val];
            //newNodes[newNode->val] = newNode;
            
            for(Node* neighbor : curNode->neighbors) {
                if(!newNodes.contains(neighbor->val)) {
                    Node* newNeigh = new Node(neighbor->val);
                    newNodes[newNeigh->val] = newNeigh;
                    q.push(neighbor);
                }
                newNode->neighbors.push_back(newNodes[neighbor->val]);
            }
        }

        return head;
    }
};
