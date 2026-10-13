class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<int> steps;
        steps.push_back(1);
        steps.push_back(2);
        for(int i = 2; i < n; ++i) {
            //- - - -
            //0, 1, 2, 3, 5
            steps.push_back(steps[i-2]+steps[i-1]);
        }

        return steps[steps.size()-1];
    }
};
