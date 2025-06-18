# Best Time to Buy and Sell Stock
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxP = 0;
        int b = 0;
        int s = 1;
        while (s < n) {
            int p = prices[s] - prices[b];
            if (p < 0) {
                b++;
            } else {
                maxP = max(maxP, p);
                s++;
            }
        }
 
        return maxP;
    }
};
