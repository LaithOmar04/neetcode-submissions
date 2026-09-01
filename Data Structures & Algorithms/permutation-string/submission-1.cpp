class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //int freq[26] = {0};
        // get freqs of s1
        // compare freq to all possible substrings in s2 that are
        // at least of size s1.size()
        if(s2.size() < s1.size()) {
            return false;
        }

        array<int, 26> freq1 = {0};
        for(const auto& c : s1) {
            ++freq1[c - 'a'];
        }

        array<int, 26> freq2 = {0};
        int i = 0;
        while(i <= s2.size() - s1.size()) {
            freq2.fill(0);
            for(int j = 0; j < s1.size(); ++j) {
                ++freq2[s2[i + j] - 'a'];
            }

            if(freq1 == freq2) {
                return true;
            }

            ++i;
        }

        return false;
    }
};
