class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> dupes;

        for(const auto& num: nums) {
            if(dupes.contains(num)) {
                return true;
            }
            dupes[num] = true;
        }
        return false;
    }
};