class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(grid[i][j] == '1') {
                    bfs(grid, i, j);
                    ++islands;
                }
            }
        }

        return islands;
    }

    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = '0';
        int directions[4][2] = {{1,0}, {0,-1}, {-1,0}, {0,1}};

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i) {
                int newRow = directions[i][0] + node.first;
                int newCol = directions[i][1] + node.second;
                if(newRow >= 0 && newCol >= 0 && newRow < grid.size() && newCol < grid[0].size() && grid[newRow][newCol] == '1') {
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = '0';
                }
            }
        }
    }
};
