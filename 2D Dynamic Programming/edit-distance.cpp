// Time & Space = O(mn)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // base case: word1 -> empty word2
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        // base case: empty word1 -> word2
        for (int j = 0; j <= n; j++) dp[0][j] = j;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
        return dp[m][n];
    }
};

// Optimal Space O(n)
// only store curr and prev rows
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> prev(n + 1), curr(n + 1);

        // base case: empty word1 -> word2
        for (int j = 0; j <= n; j++) prev[j] = j;

        for (int i = 1; i <= m; i++) {
            curr[0] = i;  // base case: word1 -> empty word2
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1])
                    curr[j] = prev[j-1];
                else
                    curr[j] = 1 + min({prev[j-1], prev[j], curr[j-1]});
            }
            swap(prev, curr);
        }

        return prev[n];
    }
};



class Solution {
public:
    int dfs(string& word1, string& word2, int i, int j, vector<vector<int>>& memo) {
        if (j == 0) return i;
        if (i == 0) return j;

        if (memo[i][j] != -1) return memo[i][j];

        if (word1[i-1] == word2[j-1]) {
            return memo[i][j] = dfs(word1, word2, i-1, j-1, memo);
        } else {
            int repl = dfs(word1, word2, i-1, j-1, memo);
            int del = dfs(word1, word2, i-1, j, memo);
            int ins = dfs(word1, word2, i, j-1, memo);
            return memo[i][j] = 1 + min({repl, del, ins});
        }
    }

    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

        return dfs(word1, word2, m, n, memo);
    }
};



//     ""  r  o  s
// ""   0  1  2  3
// h    1  1  2  3
// o    2  2  1  2
// r    3  2  2  2
// s    4  3  3  2
// e    5  4  4  3