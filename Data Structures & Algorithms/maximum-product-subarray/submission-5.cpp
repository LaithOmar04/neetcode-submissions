class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        vector<pair<int, int>> prods(nums.size());
        prods[0] = {nums[0], nums[0]};

        int maxProd = INT_MIN;
        for(int i = 1; i < nums.size(); ++i) {
            pair<int, int> cur;
            cur.first = min(prods[i-1].first*nums[i], prods[i-1].second*nums[i]);
            cur.first = min(cur.first, nums[i]);
            cur.second = max(prods[i-1].first*nums[i], prods[i-1].second*nums[i]);
            cur.second = max(cur.second, nums[i]);

            prods[i].first = cur.first;
            prods[i].second = cur.second;
            maxProd = max(maxProd, prods[i].second);
        }

        return maxProd;
    }
};
