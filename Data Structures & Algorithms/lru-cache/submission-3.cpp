struct ListNode {
    int key;
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode(int k = 0, int v = 0) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, ListNode*> keyNode;
    int maxCapacity = 0;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

public:
    LRUCache(int capacity) {
        maxCapacity = capacity;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!keyNode.contains(key)) return -1;

        ListNode* node = keyNode[key];
        
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;

        return node->val;
    }

    void put(int key, int value) {
        if(keyNode.contains(key)) {
            ListNode* node = keyNode[key];
            node->val = value;
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->next = tail;
            node->prev = tail->prev;
            tail->prev->next = node;
            tail->prev = node;

            keyNode[key] = node;

            return;
        }
        if(keyNode.size() >= maxCapacity) {
            ListNode* lru = head->next;
            lru->prev->next = lru->next;
            lru->next->prev = lru->prev;
            
            keyNode.erase(lru->key);
            delete lru;
        }

        ListNode* node = new ListNode(key, value);
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;

        keyNode[key] = node;
    }
};
