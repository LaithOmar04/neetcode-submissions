class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> map;

    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        this->map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        // if(!this->map.contains(key)) {
        //     return "";
        // }

        auto& curPairGroup = this->map[key];

        string prevRes = "";
        int l = 0, r = curPairGroup.size() - 1;
        while(l <= r) {
            int m = (l + r) / 2;

            if(curPairGroup[m].second < timestamp) {
                prevRes = curPairGroup[m].first;
                l = m + 1;
            } else if(curPairGroup[m].second > timestamp) {
                r = m - 1;
            } else {
                return curPairGroup[m].first;
            }
        }
        
        return prevRes;
    }
};
