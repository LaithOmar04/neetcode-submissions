class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) { return 0; }
        int buy = 0, sell = 1;

        int maxP = INT_MIN;
        while(sell < prices.size()) {
            if(prices[sell] < prices[buy]) {
                buy = sell; 
                ++sell;
                continue;
            }

            maxP = max(maxP, (prices[sell] - prices[buy]));
            ++sell;
        }

        return max(maxP, 0);
    }
};
