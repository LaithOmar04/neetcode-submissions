class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        vector<bool> used(nums.size(), false);
        dfs(nums, res, subset, used);
        return res;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, vector<bool>& used) {
        if(subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(used[i]) {
                continue;
            }

            used[i] = true;
            subset.push_back(nums[i]);
            dfs(nums, res, subset, used);
            used[i] = false;
            subset.pop_back();
        }
    }
};
