// 70. climbing stairs
// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    unordered_map<int,int> memo;
    int dfs(int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        if (memo.count(n)) return memo[n];
        int count = dfs(n-1) + dfs(n-2);
        memo[n]=count;
        return count;
    }

    int climbStairs(int n) {
        return dfs(n);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n) for memoization
// Alternative solution using dynamic programming:

class Solution {
public:     
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1);
        dp[0] = 1; // 1 way to stay on the ground
        dp[1] = 1; // 1 way to reach the first step
        dp[2] = 2; // 2 ways to reach the second step (1+1 or 2)
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};