class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        map<int, vector<int>, greater<int>> counts;
        int curCount = 0;
        int curNum = nums[0];
        curCount++;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == curNum) {
                curCount++;
            } else{
                counts[curCount].push_back(curNum);
                curNum = nums[i];
                curCount = 1;
            }
        }

        counts[curCount].push_back(curNum);

        vector<int> res;
        for(const auto& [key, value] : counts) {
            for(const auto& num : value) {
                res.push_back(num);
                if(res.size() == k) {
                    return res;
                }
            }
        }

        return {};
    }
};
