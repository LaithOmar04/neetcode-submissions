class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> arr;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                arr.push_back(matrix[i][j]);
            }
        }

        int i = 0;
        int j = arr.size() - 1;
        while(i <= j) {
            int mid = (i + j) / 2;

            if(arr[mid] < target) {
                i = mid + 1;
            } else if (arr[mid] > target) {
                j = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
