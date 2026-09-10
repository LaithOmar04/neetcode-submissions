class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> arr(nums.size()-1, 0);
        for(const auto& num : nums) {
            if(arr[num-1]) {
                return num;
            } else {
                arr[num-1] = 1;
            }
        }
        return -1;
    }
};
