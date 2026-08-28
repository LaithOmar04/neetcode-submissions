class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            int mid = (l + r) / 2;

            if(nums[mid] >= nums[l]) { // second section
                if(nums[mid] > target) {
                    if(nums[l] > target) { // target right
                        l = mid + 1;
                    } else { // target left
                        r = mid - 1;
                    }
                } else if(nums[mid] < target) { 
                    if(nums[l] >= target) { // target left
                        r = mid - 1;
                    } else { // target right
                        l = mid + 1;
                    }
                } else {
                    return mid;
                }
            } else { // first section
                if(nums[mid] > target) { // if t in 1st, -> else <-
                    if(nums[r] > target) { // go left, t in 1st
                        r = mid - 1;
                    } else { // go right, t in 2nd
                        l = mid + 1;
                    }
                } else if(nums[mid] < target) {
                    if(nums[r] >= target) { // go right. t in 1st
                        l = mid + 1;
                    } else { // go left, t in 2nd
                        r = mid - 1;
                    }
                } else {
                    return mid;
                }
            }
        }

        return -1;
    }
};
