class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int numFresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    ++numFresh;
                }
            }
        }

        if(numFresh == 0) return 0;

        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int minutes = -1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int j = 0; j < 4; ++j) {
                    int newRow = row + dir[j][0];
                    int newCol = col + dir[j][1];
                    if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        --numFresh;
                    }
                }
            }

            ++minutes;
        }

        if(numFresh == 0) return minutes;
        return -1;
        //return numFresh == 0 ? minutes : -1;
    }
};
