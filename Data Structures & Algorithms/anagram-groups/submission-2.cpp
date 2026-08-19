    class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> groups;

            for(const auto& str : strs) {
                array<int, 26> arr{};
                for(char ch : str) {
                    arr[ch - 'a']++;
                }
                string key = makeKey(arr);
                groups[key].push_back(str);
            }

            vector<vector<string>> anas;
            for(const auto& [key, value] : groups) {
                anas.push_back(value);
            }

            return anas;
        }

        string makeKey(const array<int,26>& freq) {
            string key;
            key.reserve(26 * 3); // small optimization

            for (int x : freq) {
                key += to_string(x);
                key += '#';
            }
            return key;
        }
    };