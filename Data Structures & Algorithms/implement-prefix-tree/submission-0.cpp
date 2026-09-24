class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        for(int i = 0; i < 26; ++i) {
            children[i] = nullptr;
            endOfWord = false;
        }
    }
};

class PrefixTree {
public:

    TrieNode* root;

    PrefixTree() {
        this->root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* cur = this->root;
        for(const auto& c : word) {
            if(cur->children[c - 'a'] != nullptr) {
                cur = cur->children[c - 'a'];
            } else {
                cur->children[c - 'a'] = new TrieNode;
                cur = cur->children[c - 'a'];
            }
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = this->root;
        for(const auto& c : word) {
            if(cur->children[c - 'a'] != nullptr) {
                cur = cur->children[c - 'a'];
            } else {
                return false;
            }
        }
        return cur->endOfWord ? true : false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = this->root;
        for(const auto& c : prefix) {
            if(cur->children[c - 'a'] != nullptr) {
                cur = cur->children[c - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }
};
