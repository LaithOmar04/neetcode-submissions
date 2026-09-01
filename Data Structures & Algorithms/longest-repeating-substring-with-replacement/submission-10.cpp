class Solution {
public:
    int characterReplacement(string s, int k) {
        int counts[26] = {0};
        int maxWindow = 0;
        int l = 0;
        int maxf = 0;

        for(int r = 0; r < s.size(); ++r) {
            ++counts[s[r] - 'A'];
            maxf = max(maxf, counts[s[r] - 'A']);
            
            while((r - l + 1) - maxf > k) {
                --counts[s[l] - 'A'];
                ++l;
            }

            maxWindow = max(maxWindow, r - l + 1);
        }

        return maxWindow;
    }
};
