// memoization
// T: O(mn)
// S: O(mn)
class Solution {
public:
    vector<vector<int>> memo;
    int m, n;
    int dfs(vector<vector<int>>& grid, int r, int c) {
        // out of bounds
        if (r == m || c == n ) return 0;

        if (memo[r][c] != -1) return memo[r][c];

        // obstacle
        if (grid[r][c] == 1) return 0;
        // reach dst
        if (r == m - 1 && c == n - 1) return 1;

        int right = dfs(grid, r, c + 1);
        int down = dfs(grid, r + 1, c);
        return memo[r][c] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        memo.resize(m, vector<int>(n, -1));
        return dfs(obstacleGrid, 0, 0);
    }
};