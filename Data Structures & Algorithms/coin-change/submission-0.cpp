class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> numCoins(amount+1, amount+1);
        numCoins[0] = 0;
        for(int i = 1; i < numCoins.size(); ++i) {
            for(const auto coin : coins) {
                if(i - coin >= 0) {
                    numCoins[i] = min(numCoins[i], 1+numCoins[i -coin]);
                }
            }
        }

        if(numCoins[amount] == amount+1) return -1;
        return numCoins[amount];
    }
};
