class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        dfs(nums, res, subset, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int i) {
        res.push_back(subset);

        for(int idx = i; idx < nums.size(); ++idx) {
            if(idx > i && nums[idx] == nums[idx-1]) {
                continue;
            }
            subset.push_back(nums[idx]);
            dfs(nums, res, subset, idx+1);
            subset.pop_back();
        }
    }
};
