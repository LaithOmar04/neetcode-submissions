class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;

        vector<vector<int>> adjNodes(n);
        for(const auto& edge : edges) {
            adjNodes[edge[0]].push_back(edge[1]);
            adjNodes[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        if(!dfs(0, 0, adjNodes, visited)) return false;

        for(int i = 0; i < n; ++i) {
            if(!visited[i]) return false;
        }

        return true;
    }

    bool dfs(int curNode, int parent, vector<vector<int>>& adjNodes, vector<bool>& visited) {
        if(visited[curNode]) return false;
        visited[curNode] = true;

        for(int node : adjNodes[curNode]) {
            if(node == parent) continue;
            if(!dfs(node, curNode, adjNodes, visited)) return false;
        }

        return true;
    }
};
