class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && prices[i] <= prices[stk.top()]) {
                int idx = stk.top(); stk.pop();
                prices[idx] -= prices[i];
            }

            stk.push(i);
        }
        return prices;
    }
};