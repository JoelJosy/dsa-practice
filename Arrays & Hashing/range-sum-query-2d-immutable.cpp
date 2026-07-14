// 2D prefix sum
// T: O(1) for sumregions
// S: O(m*n)
class NumMatrix {
public:
    // prefix sums
    vector<vector<int>> prefixsum;
    int m;
    int n;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        prefixsum.resize(m, vector<int>(n, 0));
        
        // init 0th row and col
        prefixsum[0][0] = matrix[0][0];
        for (int j = 1; j < n; j++) {
            prefixsum[0][j] = matrix[0][j] + prefixsum[0][j-1];
        }
        for (int i = 1; i < m; i++) {
            prefixsum[i][0]= matrix[i][0] + prefixsum[i-1][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prefixsum[i][j] += prefixsum[i-1][j] + prefixsum[i][j-1] + matrix[i][j] - prefixsum[i-1][j-1];
                // subtract overlapping region
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = prefixsum[row2][col2];

        if (row1 > 0)
            ans -= prefixsum[row1-1][col2];

        if (col1 > 0)
            ans -= prefixsum[row2][col1-1];

        if (row1 > 0 && col1 > 0)
            ans += prefixsum[row1-1][col1-1];
        return ans;
    }
};


// row prefix sum
// T: O(m)
// S: O(m*n)
class NumMatrix {
public:
    // prefix sums
    vector<vector<int>> prefixsum;
    int m;
    int n;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        prefixsum.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            prefixsum[i][0] = matrix[i][0];
            for (int j = 1; j < n; j++) {
                prefixsum[i][j] = prefixsum[i][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int row = row1; row <= row2; row++) {
            if (col1 - 1 >= 0)
                sum += prefixsum[row][col2] - prefixsum[row][col1-1];
            else 
                sum += prefixsum[row][col2];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */