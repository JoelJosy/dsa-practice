// Memoization
// Time: O(n* totsum)
// Space: O(n* totsum)

class Solution {
public:
    int totsum = 0;
    int dfs(vector<int>& nums, int target, int currsum, int i, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return (currsum == target) ? 1 : 0;
        }

        if (dp[i][currsum+totsum] != -1) return dp[i][currsum+totsum];

        // add 
        int addways = dfs(nums, target, currsum + nums[i], i+1, dp);
        // subtract
        int subways = dfs(nums, target, currsum - nums[i], i+1, dp);
        return dp[i][currsum+totsum] = addways + subways;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // dp[i][currsum] -> no of ways to get target, using nums[i...n] with currsum
        // we track totalsum, as sums can be negative
        // sums range from -totalsum to +totalsum
        // so offset s, but totsum everytime for valid state
        for (int x : nums) totsum += x;
        vector<vector<int>> dp (n, vector<int>(2 * totsum + 1, -1));
        return dfs(nums, target, 0, 0, dp);
    }
};


// Tabulation

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totsum = 0;
        for (int x : nums) totsum += x;

        // out of range target
        if (abs(target) > totsum) return 0;

        // n+1 rows because base case is at i == n
        vector<vector<int>> dp(n + 1, vector<int>(2 * totsum + 1, 0));

        // base case: at i=n, only currsum==target is valid
        dp[n][target + totsum] = 1;

        // fill bottom up (i = n-1 down to 0)
        for (int i = n - 1; i >= 0; i--) {
            for (int currsum = -totsum; currsum <= totsum; currsum++) {
                int addResult = 0, subResult = 0;

                // bounds check before looking up
                if (currsum + nums[i] + totsum <= 2 * totsum)
                    addResult = dp[i+1][currsum + nums[i] + totsum];
                if (currsum - nums[i] + totsum >= 0)
                    subResult = dp[i+1][currsum - nums[i] + totsum];

                dp[i][currsum + totsum] = addResult + subResult;
            }
        }

        return dp[0][totsum];  // i=0, currsum=0
    }
};