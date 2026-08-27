class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temps;
        vector<int> res(temperatures.size());

        int prevInt = INT_MAX;
        for(int i = 0; i < temperatures.size(); ++ i) {
            int curInt = temperatures[i];
            
            if(curInt <= prevInt) {
                temps.push(i);
                prevInt = curInt;
                continue;
            }

            while(!temps.empty() && temperatures[temps.top()] < curInt) {
                int distance = i - temps.top();
                res[temps.top()] = distance;
                temps.pop();
            }

            prevInt = curInt;
            temps.push(i);
        }

        return res;
    }
};
