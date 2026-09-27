class Solution {
public:
    struct MaxCompare {
        bool operator()(const pair<float, vector<int>>& a, const pair<float, vector<int>>& b) const {
            return a.first < b.first;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, vector<int>>, vector<pair<float, vector<int>>>, MaxCompare> maxHeap;
        for(auto& point : points) {
            float distance = getDistance(point);
            maxHeap.push({distance, point});
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while(!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }

    float getDistance(vector<int>& point) {
        return sqrt(pow((point[0] - 0), 2) + pow((point[1] - 0), 2));
    }
};
