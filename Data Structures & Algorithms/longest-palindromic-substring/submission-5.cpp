class Solution {
public:
    string longestPalindrome(string s) {
        string curPal = "";

        for(int i = 0; i < s.size(); ++i) {
            int left = i, right = i;
            string curStr;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                if(right - left + 1 > curPal.size()) {
                    curPal = s.substr(left, right-left+1);
                }
                --left;
                ++right;
            }
            left = i;
            right = left+1;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                if(right - left + 1 > curPal.size()) {
                    curPal = s.substr(left, right-left+1);
                }
                --left;
                ++right;
            }
        }

        return curPal;
    }
};
