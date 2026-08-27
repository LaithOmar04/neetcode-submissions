class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int end = nums.size() - 1;
        
        if(nums[l] < nums[r] || nums.size() == 1) { return nums[0]; }
        if(nums[end] < nums[0] && nums[end] < nums[end - 1]) { return nums[end]; }

        while(l <= r) {
            int mid = (l + r) / 2;
            cout << mid << " ";

            if(mid != 0 && nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }

            // l = 0, r = 1, m = 0
            if(nums[mid] > nums[end]) {
                l = mid + 1;
                continue;
            } else {
                r = mid - 1;
                continue;
            }

            // 5, 0, 1, 2, 3
        }


        return -1;
    }
};
