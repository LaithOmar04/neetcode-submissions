class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copy = strs;
        for(int i = 0; i < strs.size(); ++i) {
            sort(strs[i].begin(), strs[i].end());
        }

        unordered_map<string, vector<string>> anas;

        for(int i = 0; i < strs.size(); ++i) {
            anas[strs[i]].push_back(copy[i]);
        }

        vector<vector<string>> groups;
        for(const auto& [key, value] : anas) {
            groups.push_back(value);
        }

        return groups;
    }

    bool isAnagram(string str1, string str2) {
        if(str1.length() != str2.length()) { return false; }

        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        return str1 == str2;
    }
};
