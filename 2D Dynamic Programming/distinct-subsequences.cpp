// T: O(mn)
// S: O(mn)
class Solution {
public:
    int dfs(int i, int j, string& s, string& t, vector<vector<int>>& memo) {
        int m = s.size();
        int n = t.size();

        // t is empty -> ""
        if (j == n) return 1;
        // s is empty -> ""
        if (i == m) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == t[j]) {
            // either choose curr from s, or skip and see next
            memo[i][j] = dfs(i+1, j+1, s, t, memo) + dfs(i+1, j, s, t, memo);
            return memo[i][j];
        } else {
            // skip i
            memo[i][j] = dfs(i+1, j, s, t, memo);
            return memo[i][j];
        }

    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        return dfs(0, 0, s, t, memo);
    }
};

// Space Optimized 
// S: O(n)
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<uint> dp(n + 1, 0);
        vector<uint> next(n + 1, 0);
        
        // empty t
        next[n] = 1; 

        for (int i = m - 1; i >= 0; i--) {
            dp[n] = 1;
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[j] = next[j] + next[j+1];
                } else {
                    dp[j] = next[j];
                }
            }
            next = dp;
        }

        return next[0];
    }
};


// Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        for (int i = 0; i <= m; i++) 
            dp[i][n] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i+1][j] + dp[i+1][j+1];
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }

        return dp[0][0];
    }
};
