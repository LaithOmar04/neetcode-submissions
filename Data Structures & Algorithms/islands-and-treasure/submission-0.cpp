class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dist = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                pair<int, int> node = q.front();
                q.pop();

                int row = node.first;
                int col = node.second;

                checkRoom(grid, row-1, col, q, dist);
                checkRoom(grid, row, col+1, q, dist);
                checkRoom(grid, row+1, col, q, dist);
                checkRoom(grid, row, col-1, q, dist);
            }

            ++dist;
        }
    }

    void checkRoom(vector<vector<int>>& grid, int row, int col, queue<pair<int, int>>& q, int dist) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != 2147483647) {
            return;
        }

        grid[row][col] = dist;
        q.push({row, col});
    }
};
