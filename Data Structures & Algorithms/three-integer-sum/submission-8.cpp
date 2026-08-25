class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res; 
        for(int i = 0; i < nums.size(); ++i) {
            if(i != 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int begin = i + 1;
            int end = nums.size() - 1;
            while(begin < end) {
                int sum = nums[i] + nums[begin] + nums[end];
                if(sum > 0) {
                    --end;
                } else if(sum < 0) {
                    ++begin;
                } else {
                    res.push_back({nums[i], nums[begin], nums[end]});
                    
                    ++begin;
                    while(begin < nums.size() - 1 && nums[begin] == nums[begin - 1]) {
                        ++begin;
                    }
                }
            }
        }

        return res;
    }
};
