class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) { return s.size(); }

        unordered_set<char> seen;
        int l = 0, r = 1, curLength = 1, longest = 1;
        seen.insert(s[0]);

        while(r < s.size()) {
            if(!seen.contains(s[r])) {
                seen.insert(s[r]);
                longest = max(longest, r - l + 1);
                ++r;
            } else {
                while(seen.contains(s[r])) {
                    seen.erase(s[l]);
                    ++l;
                }

                seen.insert(s[r]);
                ++r;
            }
        }

        return max(longest, 0);
    }
};
