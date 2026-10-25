class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> int2Char = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;
        string subset = "";
        dfs(digits, res, subset, int2Char, 0);
        return res;
    }

    void dfs(string& digits, vector<string>& res, string& subset, vector<string>& int2Char, int i) {
        if(subset.size() == digits.size()) {
            res.push_back(subset);
            return;
        }

        for(char c : int2Char[digits[i] - '0']) {
            subset.push_back(c);
            dfs(digits, res, subset, int2Char, i+1);
            subset.pop_back();
        }
    }
};
