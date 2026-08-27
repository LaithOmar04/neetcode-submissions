class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int n = matrix[0].size();

        int i1 = 0, j1 = 0;
        int i2 = matrix.size() - 1, j2 = n - 1;

        while(getNumBlocks(i1, j1, n) <= getNumBlocks(i2, j2, n)) {
            int midNumBlocks = (getNumBlocks(i1, j1, n) + getNumBlocks(i2, j2, n)) / 2;

            int idx1, idx2;
            getIdx(midNumBlocks, idx1, idx2, n);

            if(matrix[idx1][idx2] < target) {
                getIdx(midNumBlocks + 1, i1, j1, n);
            } else if(matrix[idx1][idx2] > target) {
                getIdx(midNumBlocks - 1, i2, j2, n);
            } else {
                return true;
            }
        }

        return false;
        // int numBlocks for [i][j] is (i*matrix[0].size()) + j + 1;

        // int n = matrix[0].size()
        // if numBlocks <= n { i = 0 }
        // i = numBlocks % n == 0 ? (numBlocks / n) - 1 : numBlocks / n 

        // if numBlocks <= n { j = numBlocks - 1 }
        // j = numBlocks - (n * (i)) - 1

    }

    int getNumBlocks (const int i, const int j, const int n) {
        return (i * n) + j + 1;
    }

    void getIdx (const int numBlocks, int& i, int& j, const int n) {
        if(numBlocks <= n) { 
            i = 0; 
            j = numBlocks - 1;
            
            return;
        }
 
        i = numBlocks % n == 0 ? 
            (numBlocks / n) - 1 : 
            numBlocks / n;
        j = numBlocks - (n * (i)) - 1;
        
        return; 
    }
};
