class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> lowestLeft(prices.size());
        int lowest = INT_MAX;
        for(int i = 0; i < prices.size(); ++i) {
            if(i == 0) {
                lowest = prices[i];
                lowestLeft[i] = lowest;
                continue;
            }

            lowestLeft[i] = lowest;
            lowest = min(lowest, prices[i]);
        }

        int profit = INT_MIN;
        for(int i = 0; i < prices.size(); ++i) {
            if(i == 0) { continue; }

            if(prices[i] - lowestLeft[i] > profit) {
                profit = prices[i] - lowestLeft[i];
            }
        }

        return max(profit, 0);
    }
};
