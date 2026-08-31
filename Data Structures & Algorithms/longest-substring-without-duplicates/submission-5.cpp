class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) { return s.size(); }
        
        unordered_set<char> seen;
        int l = 0, r = l, curLength = 0, longest = INT_MIN;
        
        seen.insert(s[l]);
        ++curLength;
        longest = curLength;
        while(r < s.size() - 1) {
            ++r;
            if(!seen.contains(s[r])) {
                seen.insert(s[r]);
                ++curLength;
                longest = max(longest, curLength);
            } else {
                while(l < r && seen.contains(s[r])) {
                    seen.erase(s[l]);
                    ++l;
                }
                seen.insert(s[r]);
                curLength = r - l + 1;
            }
            // cout << l << " " << r << " " << curLength << endl;
        } //bbbbb

        return longest;
    }
};
