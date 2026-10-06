class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, target, res, subset, 0, 0);

        return res;
    }
    void dfs(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& subset, int i, int curSum) {
        if(curSum >= target || i >= nums.size()) {
            if(curSum == target) {
                res.push_back(subset);
            }
            return;
        }

        subset.push_back(nums[i]);
        curSum += nums[i];
        dfs(nums, target, res, subset, i, curSum);
        //dfs(nums, target, res, subset, i+1, curSum);
        subset.pop_back();
        curSum -= nums[i];
        dfs(nums, target, res, subset, i+1, curSum);
    }
};
