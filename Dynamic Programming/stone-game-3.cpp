// T: O(n)
// S: O(n) 
// n -> val size
class Solution {
public:
    // idx, score difference
    vector<int> memo; 
    int dfs(vector<int>& vals, int i) {
        if (i == vals.size()) return memo[i] = 0;
        if (memo[i] != INT_MIN) return memo[i];

        int bestscore = INT_MIN;
        int sum = 0;
        for (int take = 0; take < 3; take++) {
            if (i + take >= vals.size()) break;

            sum += vals[i+take];
            bestscore = max(bestscore, 
                            sum - dfs(vals, i + take + 1));
        }
        return memo[i] = bestscore;       
    }

    string stoneGameIII(vector<int>& stoneValue) {
        memo.resize(stoneValue.size() + 1, INT_MIN);
        int res = dfs(stoneValue, 0);
        if (res == 0) return "Tie";
        else if (res > 0) return "Alice";
        else return "Bob";
    }
};

// minimax dp
// greedy doesnt work here
// dfs(i) = best score difference (current player - opponent)
// starting from index i.
//
// take 1, 2, or 3 stones.
// gain = sum of taken stones.
// ppponent then gets dfs(next).
//
// net gain = sum - dfs(next).
// choose the maximum net gain.

// DP
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0); 

        for (int i = n - 1; i >= 0; i--) {
            int sum = 0;
            dp[i] = INT_MIN;
            for (int take = 0; take < 3 && i + take < n; take++) {
                sum += stoneValue[i + take];
                dp[i] = max(dp[i],
                            sum - dp[i + take + 1]);
            }
        }

        int res = dp[0];
        if (res == 0) return "Tie";
        else if (res > 0) return "Alice";
        else return "Bob";
    }
};
