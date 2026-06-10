// T: O(n^2)
// S: O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // transpose
        for (int i = 0; i < n; i++) {
            // consider upper triangular part only
            for (int j = i+1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // flip
        for (int row = 0; row < n; row++) {
            int l = 0;
            int r = n - 1;
            while (l <= r) {
                swap(matrix[row][l], matrix[row][r]);
                l++;
                r--;
            }
        }
    }
};
// First do transpose -> convert rows to columns
// flip matrix horizontally