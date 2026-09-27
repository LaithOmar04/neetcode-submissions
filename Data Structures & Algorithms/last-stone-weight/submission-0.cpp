class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(const int& stone : stones) {
            heap.push(stone);
        }

        while(heap.size() > 1) {
            int stone1 = heap.top();
            heap.pop();
            int stone2 = heap.top();
            heap.pop();
            if(stone1 > stone2) {
                heap.push(stone1 - stone2);
            } else if(stone1 < stone2) {
                heap.push(stone2 - stone1);
            }
        }

        return heap.size() > 0 ? heap.top() : 0;
    }
};
