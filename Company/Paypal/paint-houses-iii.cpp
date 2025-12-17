class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // cost[i][j] house i, color j+1
        // house[i] color of house i
        // target no of neighborhoods
        
        int dfs(int i, int t, int p) {
            // base case: all houses processed
            if (i == m)
                return (t == 0 ? 0 : INT_MAX);

            // pruning: impossible to form required neighborhoods
            if (t < 0 || m - i < t)
                return INT_MAX;

            // already computed
            int &res = dp[i][t][p];
            if (res != -1)
                return res;

            res = INT_MAX;

            if (houses[i] != 0) {
                // already painted
                int newT = t - (houses[i] != p);
                res = dfs(i + 1, newT, houses[i]);
            } else {
                // try painting with each color
                for (int c = 1; c <= n; c++) {
                    int newT = t - (c != p);
                    int sub = dfs(i + 1, newT, c);
                    if (sub != INT_MAX)
                        res = min(res, cost[i][c - 1] + sub);
                }
            }

            return res;
        }


        // dp[i][t][p] = min cost to paint from i to end with t neighborhoods left, previous color p
        houses = houses_;
        cost = cost_;
        m = m_;
        n = n_;
        target = target_;

        // dp[i][t][p]: min cost to paint from house i with t neighborhoods remaining, previous color p
        dp.assign(m + 1, vector<vector<int>>(target + 1, vector<int>(n + 1, -1)));

        int ans = dfs(0, target, 0);
        return (ans == INT_MAX ? -1 : ans);

    }
};
