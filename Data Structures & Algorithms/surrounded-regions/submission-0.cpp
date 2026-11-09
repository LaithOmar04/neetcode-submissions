class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> invalid(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;

        // get O's in top and bottom rows
        for(int i = 0; i < rows; ++i) {
            if(i != 0 && i != rows-1) continue;
            for(int j = 0; j < cols; ++j) {
                if(!invalid[i][j] && board[i][j] == 'O') {
                    q.push({i, j});
                    invalid[i][j] = true;
                }
            }
        }

        // get O's in left and right columns
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(j != 0 && j != cols-1) continue;
                if(!invalid[i][j] && board[i][j] == 'O') {
                    q.push({i, j});
                    invalid[i][j] = true;
                }
            }
        }

        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        // multi bfs
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                pair<int, int> curCell = q.front();
                q.pop();
                for(int j = 0; j < 4; ++j) {
                    int newX = curCell.first + dirs[j][0];
                    int newY = curCell.second + dirs[j][1];

                    if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && !invalid[newX][newY] && board[newX][newY] == 'O') {
                        q.push({newX, newY});
                        invalid[newX][newY] = true;
                    }
                }
            }
        }

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(!invalid[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
