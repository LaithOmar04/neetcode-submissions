class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        set<vector<int>> uniqueTriplets;

        for(int i = 0; i < nums.size() - 2; ++i) {
            int target = -(nums[i]);
            int begin = i + 1;
            int end = nums.size() - 1;

            while(begin < end) {
                int sum = nums[begin] + nums[end];
                if(sum < target) {
                    ++begin;
                    continue;
                } else if(sum > target) {
                    --end;
                    continue;
                } else {
                    vector<int> triplet = {nums[i], nums[begin], nums[end]};
                    uniqueTriplets.insert(triplet);
                    ++begin;
                    --end;
                }
            }
        }

        return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
    }
};
