class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int curLength = 0;
        int longest = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(i == 0) {
                curLength++;
                if(curLength > longest) {
                    longest = curLength;
                }
                continue;
            }

            if(nums[i] == nums[i - 1] + 1) {
                curLength++;
                if(curLength > longest) {
                    longest = curLength;
                }
                continue;
            }
            else if(nums[i] == nums[i - 1]) {
                continue;
            }
            else {
                curLength = 1;
            }
        }
        // 2, 3, 4, 4, 5, 10, 20

        return longest;
    }
};
