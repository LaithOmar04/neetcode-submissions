class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for(int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        vector<int> rank(n + 1, 1);
        for(const auto& edge : edges) {
            auto badEdge = unite(edge[0], edge[1], parent, rank);
            if(!badEdge.empty()) return badEdge;
        }

        return {};
    }

    int find(int node, vector<int>& parent) {
        while(parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    } 

    vector<int> unite(int n1, int n2, vector<int>& parent, vector<int>& rank) {
        int p1 = find(n1, parent);
        int p2 = find(n2, parent);
        if(p1 == p2) return {n1, n2};
        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }

        return {};
    }
};
