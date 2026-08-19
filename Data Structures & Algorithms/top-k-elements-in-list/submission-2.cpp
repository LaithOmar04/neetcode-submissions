class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;

        for(const auto& num : nums) {
            counts[num]++;
        }

        vector<vector<int>> arr(nums.size() + 1);

        for(const auto& [num, count] : counts) {
            arr[count].push_back(num);
        }

        vector<int> res;
        for(int i = nums.size(); i >= 0; --i) {
            for(const auto& curNum : arr[i]) {
                res.push_back(curNum);
                if(res.size() == k) {
                    return res;
                }
            }
        }

        return {};
    }
};
