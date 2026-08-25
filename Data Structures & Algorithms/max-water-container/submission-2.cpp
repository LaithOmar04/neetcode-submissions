class Solution {
public:
    int maxArea(vector<int>& heights) {
        int curMax = INT_MIN;
        
        int i = 0;
        int j = heights.size() - 1;

        while(i < j) {
            int area = (j - i) * min(heights[i], heights[j]);
            curMax = max(curMax, area);

            if(heights[i] > heights[j]) {
                --j;
            } else {
                ++i;
            }   
        }

        return curMax;
    }
};
