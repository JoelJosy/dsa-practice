class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        // costs[i][j] i is house, j is color

        vector<int> dp(3,0);
        dp = costs[0];

        int dp0, dp1, dp2;
        for (int i = 0; i<costs.size(); i++) {
            dp0 = costs[i][0] + min(dp[1], dp[2]);
            dp1 = costs[i][1] + min(dp[0], dp[2]);
            dp2 = costs[i][2] + min(dp[1], dp[0]);
            dp = {dp0, dp1, dp2};
        }

        return *min_element(dp.begin(), dp.end());

    }
};