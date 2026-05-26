class Solution {
public:
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();

        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        // dp[i][w]
        // max value using first i items
        // with capacity w
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                // skip current item
                dp[i][w] = dp[i - 1][w];

                // take current item if possible
                if (wt[i - 1] <= w) {
                    dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
                }
            }
        }

        return dp[n][W];
    }
};