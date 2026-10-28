class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxSize = 0;

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(grid[i][j] == 1) {
                    // int islandSize = bfs(grid, i, j);
                    // maxSize = max(maxSize, islandSize);
                    maxSize = max(maxSize, bfs(grid, i, j));
                }
            }
        }

        return maxSize;
    }

    int bfs(vector<vector<int>>& grid, int row, int col) {
        int islandSize = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 0;
        ++islandSize;
        int directions[4][2] = {{1,0}, {0,-1}, {-1,0}, {0,1}};

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i) {
                int newRow = directions[i][0] + node.first;
                int newCol = directions[i][1] + node.second;
                if(newRow >= 0 && newCol >= 0 && newRow < grid.size() && newCol < grid[0].size() && grid[newRow][newCol] == 1) {
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = 0;
                    ++islandSize;
                }
            }
        }

        return islandSize;
    }
};
