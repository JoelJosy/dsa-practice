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