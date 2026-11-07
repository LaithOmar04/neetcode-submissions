class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        stack<pair<int, int>> q;
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));

        for(int i = 0; i < heights.size(); ++i) {
            for(int j = 0; j < heights[0].size(); ++j) {
                if(i > 0 && j > 0) break;
                q.push({i, j});
                pac[i][j] = true;
            }
        }

        bfs(heights, q, pac);

        vector<vector<bool>> atl(rows, vector<bool>(cols, false));

        for(int i = 0; i < heights.size(); ++i) {
            for(int j = 0; j < heights[0].size(); ++j) {
                if(i < heights.size() - 1 && j < heights[0].size() - 1) continue;
                q.push({i, j});
                atl[i][j] = true;
            }
        }

        bfs(heights, q, atl);

        vector<vector<int>> res;
        for(int i = 0; i < heights.size(); ++i) {
            for(int j = 0; j < heights[0].size(); ++j) {
                if(pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

    void bfs(vector<vector<int>>& heights, stack<pair<int, int>>& q, vector<vector<bool>>& cells) {
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                pair<int, int> curCell = q.top();
                q.pop();
                for(int i = 0; i < 4; ++i) {
                    int newX = curCell.first + dirs[i][0];
                    int newY = curCell.second + dirs[i][1];

                    if(newX >= 0 && newX < heights.size() && newY >= 0 && newY < heights[0].size() && !cells[newX][newY] && heights[newX][newY] >= heights[curCell.first][curCell.second]) {
                        q.push({newX, newY});
                        cells[newX][newY] = true;
                    }
                }
            }
        }
    }
};
