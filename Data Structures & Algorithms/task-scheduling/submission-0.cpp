class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> letters(26);
        for(const auto& c : tasks) {
            ++letters[c-'A'];
        }

        priority_queue<int> maxHeap;
        for(int i = 0; i < 26; ++i) {
            if(letters[i] > 0) {
                maxHeap.push(letters[i]);
            }
        }

        int time = 0;
        queue<pair<int, int>> que;
        while(!maxHeap.empty() || !que.empty()) {
            ++time;

            if(!que.empty() && que.front().second <= time) {
                maxHeap.push(que.front().first);
                que.pop();
            }

            if(!maxHeap.empty()) {
                int curFreq = maxHeap.top();
                maxHeap.pop();
                if(--curFreq > 0) {
                    que.push({curFreq, time+n+1});
                }
            }
        }

        return time;
    }
};
