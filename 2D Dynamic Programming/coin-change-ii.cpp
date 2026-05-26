// dp stores max combinations for i, amount. 
// i -> coins from i can be used

// Optimal Tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins)
            for (int a = coin; a <= amount; a++)
                dp[a] += dp[a - coin];

        return dp[amount];
    }
};


// Optimal Memoization
// Time:  O(n × amount)
// Space: O(n × amount)
class Solution {
public:
    int dfs(int amount, vector<int>& coins, int i, vector<vector<int>>& memo) {
        // instead of looping through all coins
        // fix current coin, decide take/skip
        if (amount == 0) return 1;
        if (amount < 0 || i == coins.size()) return 0;

        if (memo[amount][i] != -1) return memo[amount][i];

        // skip coin i  OR  use coin i (stay at i, not i+1)
        return memo[amount][i] = dfs(amount, coins, i + 1, memo) + 
                                 dfs(amount - coins[i], coins, i, memo);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(amount + 1, vector<int>(n + 1, -1));
        return dfs(amount, coins, 0, memo);
    }
};

// Memoization
// Time: O(n * amount * n)
// Space: O(n * amount)
class Solution {
public:
    int dfs(int amount, vector<int>& coins, int i, vector<vector<int>>& memo) {
        if (amount == 0) return 1;
        if (amount < 0) return 0;

        if (memo[amount][i] != -1) return memo[amount][i];

        int combinations = 0;
        for (int j = i; j < coins.size(); j++) {
            int rem = amount - coins[j];
            combinations += dfs(rem, coins, j, memo);
        }

        return memo[amount][i] = combinations;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(amount+1, vector<int>(n+1, -1));
        return dfs(amount, coins, 0, memo);
    }
};


// Tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // base case: amount 0 = 1 way
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        // first coin row
        for (int a = 0; a <= amount; a++) {
            if (a >= coins[0])
                dp[0][a] = dp[0][a - coins[0]];
        }

        // fill table
        for (int i = 1; i < n; i++) {
            for (int a = 1; a <= amount; a++) {

                int skip = dp[i - 1][a];

                int take = 0;
                if (a >= coins[i])
                    take = dp[i][a - coins[i]];

                dp[i][a] = skip + take;
            }
        }

        return dp[n - 1][amount];
    }
};