class Solution {
    unordered_map<int, vector<char>> chars;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        //unordered_map<int, vector<char>> chars;
        char c = 'a';
        for(int i = 2; i <= 9; ++i) {
            int howMany;
            if(i == 7 || i == 9) { howMany = 4; } 
            else { howMany = 3; }
            for(int j = 0; j < howMany; ++j) {
                chars[i].push_back(c);
                ++c;
            }
        }
        vector<string> res;
        string subset;
        dfs(digits, res, subset, 0);

        return res;
    }

    void dfs(string& digits, vector<string>& res, string subset, int i) {
        if(subset.size() == digits.size()) {
            res.push_back(subset);
            return;
        }

        for(const auto c : chars[digits[i] - '0']) {
            dfs(digits, res, subset + c, i+1);
        }
    }
};
