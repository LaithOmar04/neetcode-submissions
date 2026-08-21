class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());

        int curProduct = 1;
        int zeroCount = 0;
        int zeroIdx = 0;
    
        for(int i = 1; i < nums.size(); ++i) {
            curProduct *= nums[i];
            if(nums[i] == 0) {
                ++zeroCount;
                zeroIdx = i;
            }
        }

        if (zeroCount > 1) {
            return vector<int>(nums.size());
        }
        if (zeroCount == 1) {
            curProduct = 1;
            for(int i = 0; i < nums.size(); ++i) {
                if(i == zeroIdx) { continue; }

                curProduct *= nums[i];
            }

            res[zeroIdx] = curProduct;
            return res;
        }

        res[0] = curProduct;

        for(int i = 1; i < nums.size(); ++i) {
            curProduct /= nums[i];
            curProduct *= nums[i-1];

            res[i] = curProduct;
        }

        return res;
    }
};
