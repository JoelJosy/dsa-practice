// Space Optimized
// T: O(m*n)
// S: O(1)
// use first row to mark which cols to convert
// use first col to amrk which rows to convert
// 0,0 element has to be tracked separately
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstrow = false;
        bool firstcol = false;
        
        // check first col
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) firstcol = true;
        }

        // check first row
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) firstrow = true;
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    // mark col
                    matrix[0][j] = 0;
                    // mark row
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstcol) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        if (firstrow) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};



// T: O(m*n)
// S: O(m+n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> rows(m, false);
        vector<bool> cols(n, false);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};