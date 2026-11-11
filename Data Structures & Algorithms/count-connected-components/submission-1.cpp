class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n);
        for(const auto& edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                dfs(i, -1, neighbors, visited);
                ++components;
            }
        }

        return components;
    }

    void dfs(int curNode, int parent, vector<vector<int>>& neighbors, vector<bool>& visited) {
        visited[curNode] = true;
        for(int neighbor : neighbors[curNode]) {
            if(!visited[neighbor]) {
                dfs(neighbor, curNode, neighbors, visited); 
            }
        }
    }
};
