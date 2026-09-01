class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int counts[26] = {0};
        int maxFreq = 0;
        int maxWindow = 0;

        for (int r = 0; r < s.size(); ++r) {
            ++counts[s[r] - 'A'];
            maxFreq = max(maxFreq, counts[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k) {
                --counts[s[l] - 'A'];
                ++l;

                maxFreq = 0;
                for (int i = 0; i < 26; ++i) {
                    maxFreq = max(maxFreq, counts[i]);
                }
            }

            maxWindow = max(maxWindow, r - l + 1);
        }

        return maxWindow;
    }
};
