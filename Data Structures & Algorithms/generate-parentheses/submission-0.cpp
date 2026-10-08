class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string subset = "";
        dfs(n, 0, 0, res, subset);
        return res;
    }

    void dfs(int n, int open, int close, vector<string>& res, string& subset) {
        if(close > open || close > n || open > n) {
            return;
        }
        if(subset.size() == 2*n) {
            if(open == close) {
                res.push_back(subset);
            }
            return;
        }

        if(open < n) {
            subset += "(";
            dfs(n, open+1, close, res, subset);
            subset.pop_back();
        }
        if(close < open) {
            subset += ")";
            dfs(n, open, close+1, res, subset);
            subset.pop_back();
        }
    }
};
