// T: O(mn)
// S: O(mn)

class Solution {
public:
    string s1; // pointer i
    string s2; // pointer j
    string s3; // pointer k = i + j
    bool dfs(int i, int j, vector<vector<int>>& memo) {
        int k = i + j;
        
        if (k == s3.size()) {
            if (i == s1.size() && j == s2.size())
                memo[i][j] = 1;
            else memo[i][j] = 0;
            return memo[i][j];
        }
            
        if (k > s3.size()) 
            return memo[i][j] = 0;
        
        if (memo[i][j] != -1) return memo[i][j];

        if (s3[k] == s1[i] && s3[k] == s2[j]) {
            // both s1 and s2 match chars
            // two options
            memo[i][j] = (dfs(i+1, j, memo) || dfs(i, j+1, memo));
            return memo[i][j];
        }
        else if (s3[k] == s1[i]) {
            // s1 char matches s3 char
            return memo[i][j] = dfs(i+1, j, memo);

        } else if (s3[k] == s2[j]) {
            // s2 char matches s3 char
            return memo[i][j] = dfs(i, j+1, memo);
        }
        
        // neither match
        return 0;
    }

    bool isInterleave(string st1, string st2, string st3) {
        s1 = st1;
        s2 = st2;
        s3 = st3;
        vector<vector<int>> memo(s1.size() + 1, 
                            vector<int>(s2.size() + 1, -1));
        return dfs(0, 0, memo);
    }
};

// Tabulation

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();

        if (m + n != s3.size()) return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[m][n] = true;

        // fill last row
        for (int j = n - 1; j >= 0; j--) {
            dp[m][j] = (s2[j] == s3[m + j]) && dp[m][j + 1];
        }

        // fill last col
        for (int i = m - 1; i >= 0; i--) {
            dp[i][n] = (s1[i] == s3[i + n]) && dp[i + 1][n];
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int k = i + j;

                bool takeS1 = (s1[i] == s3[k]) && dp[i + 1][j];
                bool takeS2 = (s2[j] == s3[k]) && dp[i][j + 1];

                dp[i][j] = takeS1 || takeS2;
            }
        }

        return dp[0][0];
    }
};