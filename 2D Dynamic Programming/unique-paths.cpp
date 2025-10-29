// 62. Unique Paths
// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // last row and last col are all 1 
        // so start from second last
        for (int i = m-2; i>=0; i--) {
            for (int j = n-2; j>=0; j--) {
                dp[i][j] = dp[i][j+1] + dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};