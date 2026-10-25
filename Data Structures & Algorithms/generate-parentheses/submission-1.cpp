class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string subset = "";
        dfs(n, subset, res, 0, 0);
        return res;
    }

    void dfs(int n, string& subset, vector<string>& res, int numL, int numR) {
        if(numL == numR && numL == n) {
            res.push_back(subset);
            return;
        }

        if(numL < n) {
            subset += '(';
            dfs(n, subset, res, numL+1, numR);
            subset.pop_back();
        } 

        if(numR < numL) {
            subset += ')';
            dfs(n, subset, res, numL, numR+1);
            subset.pop_back();
        }
    }
};
