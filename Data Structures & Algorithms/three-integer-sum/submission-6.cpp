class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> uniqueTriplets;
        unordered_set<string> taken;

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
                    if(!taken.contains(vecToStr(triplet))) {
                        taken.insert(vecToStr(triplet));
                        uniqueTriplets.push_back(triplet);
                    }
                    ++begin;
                    --end;
                }
            }
        }

        return uniqueTriplets;
    }

    string vecToStr(vector<int> v) {
        string s = "";
        for(int i = 0; i < v.size(); ++i) {
            s += to_string(v[i]);
        }
        return s;
    }
};
