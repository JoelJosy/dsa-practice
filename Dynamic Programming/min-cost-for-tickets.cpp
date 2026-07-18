// T: O(n * logn)
// S: O(n)
class Solution {
public:
    vector<int> memo;
    int dfs(vector<int>& days, vector<int>& costs, int i) {
        if (i == days.size())
            return 0;
        
        if (memo[i] != INT_MAX) return memo[i];

        int curr = days[i];

        int next1 = lower_bound(days.begin(), days.end(), curr + 1) - days.begin();
        int next7 = lower_bound(days.begin(), days.end(), curr + 7) - days.begin();
        int next30 = lower_bound(days.begin(), days.end(), curr + 30) - days.begin();
        
        int one = costs[0] + dfs(days, costs, next1);
        int seven = costs[1] + dfs(days, costs, next7);
        int thirty = costs[2] + dfs(days, costs, next30);

        return memo[i] = min({one, seven, thirty});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memo.resize(n, INT_MAX);
        return dfs(days, costs, 0);
    }
};