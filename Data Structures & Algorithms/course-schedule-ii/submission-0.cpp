class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preMap(numCourses);
        for(const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        vector<int> res;
        vector<int> courseState(numCourses);
        for(int i = 0; i < numCourses; ++i) {
            if(!dfs(i, preMap, courseState, res)) return {};
        }

        return res;
    }

private:
    bool dfs(int i, vector<vector<int>>& preMap, vector<int>& courseState, vector<int>& res) {
        if(courseState[i] == 1) return false;
        if(courseState[i] == 2) return true;

        courseState[i] = 1;
        for(auto course : preMap[i]) {
            if(!dfs(course, preMap, courseState, res)) return false;
        }

        courseState[i] = 2;
        res.push_back(i);
        return true;
    }
};
