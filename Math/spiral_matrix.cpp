// 54. Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> res;
        
        int top = 0;
        int bottom = rows - 1;
        int left = 0;
        int right = cols - 1;
        int count = 0;
        while (top <= bottom && left <= right) {
            // Top 
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // right 
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            // bottom 
            // check for single row to prevent bottom:
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // left 
            // check for single col to prevent left:
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};