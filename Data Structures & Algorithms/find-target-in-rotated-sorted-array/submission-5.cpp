class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            int mid = (l + r) / 2;

            if(nums[mid] == target) { return mid; }
            //4, 5, 6, 1, 2, 3
            if(nums[l] <= nums[mid]) { // left sorted portion
                // in left, all larger #'s are to the right
                if(target > nums[mid]) { // go right
                    l = mid + 1;
                } else if (target < nums[l]) { // t in right portion
                    l = mid + 1;
                } else { // t in left portion
                    r = mid - 1;
                }
            } else { // right sorted portion
                // in right, all smaller #'s are to the left
                if(target < nums[mid]) { // go left
                    r = mid - 1;
                } else if(target > nums[r]) { // t in left portion
                    r = mid - 1;
                } else { // t in right portion
                    l = mid + 1;
                }
            }
        }

        return -1;
    }
};
