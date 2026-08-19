class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;

        for(const auto& num : nums) {
            counts[num]++;
        }

        unordered_set<int> taken;
        vector<int> res;
        int curMax;
        int curNum;
        for(int i = 0; i < k; ++i) {
            curMax = INT_MIN;

            for(const auto& [key, value] : counts) {
                if(value > curMax && (!taken.contains(key))) {
                    curNum = key;
                    curMax = value;
                }
            }

            res.push_back(curNum);
            taken.insert(curNum);
        }

        return res;
    }
};
