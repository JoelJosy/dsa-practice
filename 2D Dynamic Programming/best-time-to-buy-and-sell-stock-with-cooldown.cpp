// Optimal
// Time: O(n)
// Space: O(n) 

class Solution {
public:
    int dfs(vector<int>& prices, int i, bool holding, vector<vector<int>>& memo) {
        if (i >= prices.size()) return 0;
        if (memo[i][holding] != -1) return memo[i][holding];

        int ans;
        // can buy
        if (!holding) {
            int buy = -prices[i] + dfs(prices, i + 1, true, memo);
            int skip = dfs(prices, i + 1, false, memo);
            ans = max(buy, skip);
        }
        // currently holding stock
        else {
            int sell = prices[i] + dfs(prices, i + 2, false, memo);
            int hold = dfs(prices, i + 1, true, memo);
            ans = max(sell, hold);
        }
        return memo[i][holding] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return dfs(prices, 0, false, memo);
    }
};

// Tabulation

// dp[i][0] :
// Maximum profit starting from day i when you are NOT holding a stock
// dp[i][1] :
// Maximum profit starting from day i when you are holding a stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // extra 2 rows because we use i+2
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            // not holding stock
            int buy = -prices[i] + dp[i + 1][1];
            int skipBuy = dp[i + 1][0];
            dp[i][0] = max(buy, skipBuy);

            // holding stock
            int sell = prices[i] + dp[i + 2][0];
            int hold = dp[i + 1][1];
            dp[i][1] = max(sell, hold);
        }
        return dp[0][0];
    }
};


// Time: O(n^2)
// Space: O(n^2 + n) 

class Solution {
public:
    int dfs(vector<int>& prices, int i, int buy, vector<vector<int>>& memo) {
        // end case
        if (i >= prices.size()) return 0;

        if (memo[i][buy+1] != -1) return memo[i][buy+1];

        // if not bought, try buying / skipping
        if (buy == -1) {
            int take = dfs(prices, i+1, i, memo);
            int skip = dfs(prices, i+1, -1, memo);
            return memo[i][buy+1] = max(take, skip);
        }
        // if bought, try selling / skipping
        else {
            int sell = (prices[i]-prices[buy]) + dfs(prices, i+2, -1, memo);
            int skip = dfs(prices, i+1, buy, memo);
            return memo[i][buy+1] = max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // state -> i, buy
        vector<vector<int>> memo(n, vector<int>(n+1, -1));
        return dfs(prices, 0, -1, memo);
    }
};
