class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int bot = 1, top = ranges::max(piles); 
        int bestK = INT_MAX;
        while(bot <= top) {
            int k = (bot + top) / 2;
            int curHours = getTotalHours(piles, k);

            if(curHours > h) {
                bot = k + 1;
            } else {
                top = k - 1;
                if(k < bestK) {
                    bestK = k;
                }
            }
        }

        return bestK;
    }

    int getTotalHours(vector<int>& piles, const int k) {
        int totalHours = 0;
        for(int i = 0; i < piles.size(); ++i) {
            if(piles[i] % k == 0) {
                totalHours += piles[i] / k;
            } else {
                totalHours += (piles[i] / k) + 1;
            }
        }

        return totalHours;
    }
};
