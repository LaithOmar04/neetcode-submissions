class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = INT_MIN;
        for(int i = 0; i < prices.size() - 1; ++i) {
            for(int j = i + 1; j < prices.size(); ++j) {
                if(prices[j] - prices[i] > maxP) {
                    maxP = prices[j] - prices[i];
                }
            }
        }

        return max(maxP, 0);
    }
};
