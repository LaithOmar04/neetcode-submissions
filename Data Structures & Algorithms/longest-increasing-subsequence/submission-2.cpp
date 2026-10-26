class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lengths(nums.size(), 1);
        int maxLIS = 1;
        for(int i = nums.size()-1; i >= 0; --i) {
            if(i == nums.size()-1) {
                continue;
            }

            int curNum = nums[i];
            for(int j = i+1; j < nums.size(); ++j) {
                if(curNum < nums[j]) {
                    lengths[i] = max(lengths[i], 1+lengths[j]);
                    maxLIS = max(maxLIS, lengths[i]);
                }
            }
        }

        return maxLIS;
    }
    //9,1,4,2,3,3,7
    //1,4,2,3,1,2,1

    //0,1,0,3,2,3
    //4,3,3,2,2,1
};
