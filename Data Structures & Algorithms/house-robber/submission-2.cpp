class Solution {
public:
    int rob(vector<int>& nums) {
        // 1,9,8,3,6
        // 1,9,9,12,15
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> money(nums.size());
        money[0] = nums[0];
        money[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i) {
            money[i] = max(money[i-1], money[i-2]+nums[i]);
        }

        return money[money.size()-1];
    }
};
