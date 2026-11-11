class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        vector<int> rank(n, 1);
        int count = n;
        for(const auto& edge : edges) {
            count -= unite(edge[0], edge[1], parent, rank);
        }

        return count;
    }

    int findPar(int n1, vector<int>& parent) {
        while(n1 != parent[n1]) {
            parent[n1] = parent[parent[n1]];
            n1 = parent[n1];
        }

        return n1; 
    }

    int unite(int n1, int n2, vector<int>& parent, vector<int>& rank) {
        int p1 = findPar(n1, parent);
        int p2 = findPar(n2, parent);
        if(p1 == p2) return 0;

        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }

        return 1;
    }
};
