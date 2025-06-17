# Search a 2D Matrix
# https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowNum = matrix.size();
        int colNum = matrix[0].size();
        
        int l = 0;
        int r = (rowNum * colNum) - 1;
        int mid;
        while (l <= r) {
            mid = l + (r-l) / 2;
            if (target > matrix[mid / colNum][mid % colNum]) {
                l = mid + 1;
            } else if (target < matrix[mid / colNum][mid % colNum]) {
                r = mid - 1;
            } else return true;
        }
        return false;

    }
};