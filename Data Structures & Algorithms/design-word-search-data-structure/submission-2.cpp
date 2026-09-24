class TrieNode {
public:
    TrieNode* arr[26];
    bool endOfWord;

    TrieNode() : endOfWord(false) {
        for(int i = 0; i < 26; ++i) {
            arr[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(const auto& c : word) {
            int idx = c - 'a';
            if(cur->arr[idx] == nullptr) {
                cur->arr[idx] = new TrieNode();
            }
            cur = cur->arr[idx];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* cur = root;

        for(int i = j; i < word.size(); ++i) {
            char c = word[i];
            if(c == '.') {
                for(TrieNode* node : cur->arr) {
                    if(node != nullptr && dfs(word, i+1, node)) { 
                        return true;
                    }
                }
                return false;
            } else {
                if(cur->arr[c - 'a'] == nullptr) {
                    return false;
                }
                cur = cur->arr[c - 'a'];
            }
        }
        return cur->endOfWord;
    }
};