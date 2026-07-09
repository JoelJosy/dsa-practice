// T: O(n)
// S: O(n)
class Solution {
public:
    vector<vector<vector<int>>> memo;
    int dfs(vector<int>& prices, int i, int remaining, bool bought) {
        if (i >= prices.size() || remaining == 0) return 0;
        if (memo[i][remaining][bought] != -1) 
            return memo[i][remaining][bought];

        int profit;
        if (bought) {
            // skip
            int hold = dfs(prices, i + 1, remaining, bought);
            // sell
            int sell = prices[i] + dfs(prices, i+1, remaining-1, false);

            profit = max(hold, sell);
        } else {
            // skip
            int skip = dfs(prices, i+1, remaining, bought);
            // buy
            int buy = -prices[i] + dfs(prices, i+1, remaining, true);

            profit = max(skip, buy);
        }
        return memo[i][remaining][bought] = profit;
    }

    int maxProfit(vector<int>& prices) {
        memo.resize(
            prices.size(),
            vector<vector<int>> (3, 
            vector<int>(2, -1))
        );
        return dfs(prices, 0, 2, false);
    }
};

// either u can buy, skip, sell

// T: O(n)
// S: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN;
        int sell1 = 0;
        int buy2 = INT_MIN;
        int sell2 = 0;
        for (int p: prices) {
            // max(skip, buy)
            buy1 = max(buy1, -p);
            // max(skip, sell)
            sell1 = max(sell1, buy1 + p);

            buy2 = max(buy2, sell1 - p);
            sell2 = max(sell2, buy2 + p);
        }
        return sell2;
    }
};

// the process is buy1 -> sell1 -> buy2 -> sell2
// process days one by one
// What is the best profit after processing the prices seen so far?