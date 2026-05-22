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


// Memoization
class Solution {
public:
    unordered_map<string, int> memo;
    int uniquePaths(int m, int n) {
        if (m==1 && n==1) return 1;
        if (m==0 || n==0) return 0;

        string key = to_string(m) + "-" + to_string(n);
        if (memo.find(key) != memo.end()) return memo[key];


        int down = uniquePaths(m, n-1);
        int right = uniquePaths(m-1, n);

        memo[key] = down+right;
        return down+right;
    }
};

// Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j+1 < n) dp[i][j+1] += dp[i][j];
                if (i+1 < m) dp[i+1][j] += dp[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};