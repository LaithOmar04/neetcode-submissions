class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(res, candidates, subset, target, 0);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& subset, int target, int i) {
        if(target == 0) {
            res.push_back(subset);
            return;
        }
        if(target < 0 || i >= nums.size()) {
            return;
        }

        for(int idx = i; idx < nums.size(); ++idx) {
            if(idx > i && nums[idx] == nums[idx-1]) {
                continue;
            }
            subset.push_back(nums[idx]);
            dfs(res, nums, subset, target - nums[idx], idx+1);
            subset.pop_back();
        }
    }
};
