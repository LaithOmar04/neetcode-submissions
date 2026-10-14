class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //1,2,1,2,1,1,1
        //0,0,1,2,2,3,3,4
        vector<int> minCost(cost.size()+1);
        minCost[0] = 0;
        minCost[1] = 0;
        for(int i = 2; i < minCost.size(); ++i) {
            minCost[i] = min((cost[i-1]+minCost[i-1]),(cost[i-2]+minCost[i-2]));
        }
        return minCost[cost.size()];
    }
};
