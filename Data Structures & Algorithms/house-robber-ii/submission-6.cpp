class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0], nums[1]);

        vector<int> total1(size);
        total1[0] = nums[0];
        total1[1] = max(nums[0], nums[1]);
        for(int i = 2; i < size-1; ++i) {
            total1[i] = max((total1[i-1]), (total1[i-2] + nums[i]));
        }
        int totalFirst = total1[total1.size()-2];
        
        vector<int> total2(size);
        total2[1] = nums[1];
        total2[2] = max(nums[1], nums[2]);
        for(int i = 3; i < size; ++i) {
            total2[i] = max((total2[i-1]), (total2[i-2] + nums[i]));
        }
        int totalSecond = total2[size-1];

        return max(totalFirst, totalSecond);
        // 1,2,3,1
        // 1,2,4,0
        // 0,2,3,3
    }
};