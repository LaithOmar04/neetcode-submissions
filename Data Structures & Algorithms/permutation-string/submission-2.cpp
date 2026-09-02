class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) { return false; }

        array<int, 26> freq1 = {0};
        array<int, 26> curFreq = {0};

        int l = 0, r = s1.size() - 1;
        for(int i = 0; i < s1.size(); ++i) { // set s1 & s2 freqs
            ++freq1[s1[i] - 'a'];
            ++curFreq[s2[i] - 'a'];
        }

        while(r < s2.size()) {
            if(freq1 == curFreq) { return true; }

            --curFreq[s2[l] - 'a'];
            ++l;
            ++r;
            ++curFreq[s2[r] - 'a'];
        }

        return false;
    }
};
