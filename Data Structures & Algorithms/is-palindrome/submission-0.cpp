class Solution {
public:
    bool isPalindrome(string s) {
        const char* start = s.c_str();
        const char* end = s.c_str() + s.size() - 1;

        while(start <= end) {
            if(!isAlphaNum(*start)) {
                ++start;
                continue;
            } else if (!isAlphaNum(*end)) {
                --end;
                continue;
            }

            if(tolower(*start) != tolower(*end)) { return false; }

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