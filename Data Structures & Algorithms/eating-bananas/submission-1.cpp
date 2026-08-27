class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //Maybe: l = min(piles), r = max(piles), k = l + r / 2
        // if h_k > h, l = k (or maybe k + 1?)
        // else if h_k <= h, r = k (or k - 1?)
        //      curBest = h_k
        // if(h_k > max(piles)) {  break }

        // to test h_k: 
        // int totalHours = 0
        // for(pile in piles)  
        //    if pile % h_k == 0 
        //       totalhours += pile / h_k
        //    else totalHours += pile / h_k + 1

        //int min = ranges::min(piles);
        int max = ranges::max(piles);

        int bot = 1, top = max; 
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
