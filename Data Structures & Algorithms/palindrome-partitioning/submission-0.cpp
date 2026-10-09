class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> subset;
        dfs(s, res, subset, 0);
        return res;
    }

    void dfs(string& s, vector<vector<string>>& res, vector<string>& subset, int i) {
        if(i >= s.size()) {
            res.push_back(subset);
            return;
        }
        
        for(int j = i; j < s.size(); ++j) {
            if(is_pali(s, i, j)) {
                subset.push_back(s.substr(i, j-i+1));
                dfs(s, res, subset, j+1);
                subset.pop_back();
            }
        } 
    }

    bool(is_pali(string& s, int i, int j)) {
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }

        return true;
    }
};
