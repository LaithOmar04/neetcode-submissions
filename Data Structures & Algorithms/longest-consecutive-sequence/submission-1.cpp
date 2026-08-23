class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> available;
        unordered_set<int> taken;

        for(const auto& num : nums) {
            available.insert(num);
        }

        int longest = 0;
        int curLength = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(taken.contains(nums[i])) { continue; }

            bool go = true;
            int curNum = nums[i];
            while(go) {
                curLength++;
                if(curLength > longest) { longest = curLength; }
                if(available.contains(curNum + 1)) {
                    taken.insert(curNum);
                    taken.insert(curNum + 1);
                    curNum += 1;
                } else {
                    curLength = 0;
                    go = false;
                }
            }
        }

        return longest;

        // 0, 3, 2, 5, 4, 6, 1, 1
        // taken: 0, 1, 2, 3, 4, 5, 6, 
        
        // 2, 20, 4, 10, 3, 4, 5     
        // taken: 2, 3, 4, 5,    

        // 7, 6, 5, 4, 3, 2, 1, 0     
        // taken: 0, 1, 2, 3, 4, 5, 6, 7
    }
};
