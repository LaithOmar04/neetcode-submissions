class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) { return false; }

        unordered_map<char, int> seenS;
        for(const auto& letter : s) {
            if(!seenS.contains(letter)) {
                seenS[letter] = 1;
            } else {
                seenS[letter] += 1;
            }
        }

        unordered_map<char, int> seenT;
        for(const auto& letter : t) {
            if(!seenT.contains(letter)) {
                seenT[letter] = 1;
            } else {
                seenT[letter] += 1;
            }
        }

        for(const auto& [key, value] : seenS) {
            if(value != seenT[key]) { return false; }
        }

        return true;
    }
};
