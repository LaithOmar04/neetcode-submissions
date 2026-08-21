class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> set;

        for(int i = 0; i < 9; ++i) {
            for(int j  = 0; j < 9; ++j) {
                if(board[i][j] == '.') { continue; }
                if(set.contains(board[i][j])) {
                    return false;
                }
                set.insert(board[i][j]);
            }
            set.clear();
        }
        for(int j = 0; j < 9; ++j) {
            for(int i = 0; i < 9; ++i) {
                if(board[i][j] == '.') { continue; }
                if(set.contains(board[i][j])) {
                    return false;
                }
                set.insert(board[i][j]);
            }
            set.clear();
        }

        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                for(int x = i; x < i + 3; ++x) {
                    for(int y = j; y < j + 3; ++y) {
                        if(board[x][y] == '.') { continue; }
                        if(set.contains(board[x][y])) {
                            return false;
                        }
                        set.insert(board[x][y]);
                    }
                }
                set.clear();
            }
        }

        return true;
    }
};
