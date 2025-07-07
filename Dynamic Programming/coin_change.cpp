// 322 coin change
// https://leetcode.com/problems/coin-change/

// bottom up approach

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, amount+1);
        memo[0] = 0;
        // coins = [1,2,5], amount = 11
        // dp = [0,12,12,12,12,12,12,12,12,12,12,12];
        // i  = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11]

        for (int currAmt = 1; currAmt < amount+1; currAmt++) {
            for (int coin: coins) {
                if ((currAmt - coin) >= 0) {
                    memo[currAmt] = min(memo[currAmt], 1+memo[currAmt-coin]);
                }
            }
        }

        return (memo[amount] != amount+1) ? memo[amount] : -1;

    }
};



// we can do dfs/backtracking but it will be slow
// instead we can use dynamic programming to save repeated calculations

// dfs + memo (top-down approach)
class Solution {
public:
    unordered_map<int, int> memo; // map<currAmt, minCoinCount>
    
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        if (memo.count(amount)) return memo[amount];

        int res = INT_MAX;
        for (int coin: coins) {
            if (amount - coin >= 0) {
                int next = dfs(coins, amount-coin);
                if (next != -1)
                res = min(res, 1 + dfs(coins, amount-coin));
            }
        }
        memo[amount] = (res == INT_MAX) ? -1 : res;
        return memo[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
       return dfs(coins, amount);
    }
};