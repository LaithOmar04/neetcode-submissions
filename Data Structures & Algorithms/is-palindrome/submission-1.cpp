class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        
        while(start <= end) {
            if(!isAlphaNum(s[start])) {
                ++start;
                continue;
            } else if (!isAlphaNum(s[end])) {
                --end;
                continue;
            }

            if(tolower(s[start]) != tolower(s[end])) {
                return false;
            }

            ++start;
            --end;
        }

        return true;
    }

    bool isAlphaNum(char c) {
    return ('A' <= c && c <= 'Z') || 
            ('a' <= c && c <= 'z') || 
            ('0' <= c && c <= '9');
    }
};
