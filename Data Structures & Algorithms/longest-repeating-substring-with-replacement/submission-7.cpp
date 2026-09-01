class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int counts[26] = {0};
        int maxFreq = 0, maxWindow = 0;

        while(r < s.size()) {
            ++counts[s[r] - 'A'];
            maxFreq = max(maxFreq, counts[s[r] - 'A']);

            if((r - l + 1) - maxFreq <= k) {
                maxWindow = max(maxWindow, r - l + 1);
                ++r;
                continue;
            } else {
                while((r - l + 1) - maxFreq > k) {
                    --counts[s[l] - 'A'];
                    ++l;

                    maxFreq = 0;
                    for(int i = 0; i < 26; ++i) {
                        maxFreq = max(maxFreq, counts[i]);
                    }
                }
            }

            maxWindow = max(maxWindow, r - l + 1);
            ++r;
        }

        return maxWindow;
    }
};
