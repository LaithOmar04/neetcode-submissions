class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(const auto& num : nums) {
            if(seen.contains(num)) {
                return num;
            } else {
                seen.insert(num);
            }
        }

        return -1;
    }
};
