// T: O(n * rootn)
// S: O(n)
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            // if perfect sq
            int rt = sqrt(i);
            if (rt * rt == i)
                dp[i] = 1;
            
            int j = 1;
            // loop over perfect squares
            while (j * j < i) {
                int sq = j * j;
                dp[i] = min(dp[i], dp[sq] + dp[i - sq]);
                j++;
            }
        }

        return dp[n];
    }
};

// n = 8
// ans = 2
// dp[4] + dp[4] = 2
// dp[1] + dp[7] = 1 + 4
// check perfect sq < 8