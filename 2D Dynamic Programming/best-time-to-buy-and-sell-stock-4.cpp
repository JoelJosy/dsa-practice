// Space optimized
// T: O(n * k)
// S: O(k)
// if k >= n/2, unlimited transactions
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        if(n == 0)
            return 0;

        // unlimited transactions
        if(k >= n / 2) {
            int profit = 0;

            for(int i = 1; i < n; i++) {
                if(prices[i] > prices[i-1])
                    profit += prices[i] - prices[i-1];
            }

            return profit;
        }


        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);

        for(int price : prices) {

            for(int t = 1; t <= k; t++) {

                // buy stock using t transactions available
                buy[t] = max(
                    buy[t],
                    sell[t-1] - price
                );

                // sell stock and complete transaction
                sell[t] = max(
                    sell[t],
                    buy[t] + price
                );
            }
        }

        return sell[k];
    }
};


// T: O(n * k)
// S: O(n * k)
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

    int maxProfit(int k, vector<int>& prices) {
        memo.resize(
            prices.size(),
            vector<vector<int>> (k+1, 
            vector<int>(2, -1))
        );
        return dfs(prices, 0, k, false);
    }
};