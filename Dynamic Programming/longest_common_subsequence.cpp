// Memoization
// Time: O(m×n)
// Space: O(m×n) + O(m+n)
class Solution {
public:
    int dfs(string& t1, string& t2, int i, int j, vector<vector<int>>& memo) {
        int m = t1.size();
        int n = t2.size();
        
        if (i >= m || j >= n) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        if (t1[i] == t2[j]) {
            memo[i][j] = 1 + dfs(t1, t2, i+1, j+1, memo);
            return memo[i][j];
        } else {
            memo[i][j] = max(dfs(t1, t2, i+1, j, memo), 
                               dfs(t1, t2, i, j+1, memo));
            return memo[i][j];
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // i, j -> length
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));

        int res = dfs(text1, text2, 0, 0, memo);
        return res;
    }
};



// Tabulation
// Time: O(m×n)
// Space: O(m×n)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // i, j -> length
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
    }
};