class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> map;

    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        this->map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!this->map.contains(key)) {
            return "";
        }

        string res;
        int curTime = INT_MIN;
        for(const auto& p : this->map[key]) {
            if(p.second > curTime && p.second <= timestamp) {
                res = p.first;
                curTime = p.second;
            }
        }

        return res;
    }
};
