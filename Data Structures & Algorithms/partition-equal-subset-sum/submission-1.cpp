class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bool res = false;
        int total = 0;
        for(int num : nums) {
            total += num;
        }
        return dfs(nums, res, total, 0, 0);
    }

    bool dfs(vector<int>& nums, bool& res, int total, int curSum, int i) {
        if (curSum == total) return true;
        if (i == nums.size() || curSum > total) return false;

        return dfs(nums, res, total-nums[i], curSum+nums[i], i+1) || dfs(nums, res, total, curSum, i+1);
    }
};
