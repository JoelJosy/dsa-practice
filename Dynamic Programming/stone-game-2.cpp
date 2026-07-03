// T: O(n^3)
// S: O(n^2)
class Solution {
public:
    // idx, m 
    vector<vector<int>> memo; 
    int dfs(vector<int>& piles, int start, int m) {
        if (start >= piles.size()) {
            return memo[start][m] = 0;
        }
        if (memo[start][m] != INT_MIN) return memo[start][m];

        int curr = 0;
        int bestscore = INT_MIN;
        for (int x = 1; x <= 2*m; x++) {
            if (start + x - 1 >= piles.size()) break;

            curr += piles[start + x - 1];
            int netscore = curr - dfs(piles, start + x, max(m, x));
            bestscore = max(bestscore, netscore);
        }
        return memo[start][m] = bestscore;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memo.resize(n + 1, vector<int>(n + 1, INT_MIN));
        int total = accumulate(piles.begin(), piles.end(), 0);
        // alice + bob = total
        // alice - bob = net
        int net = dfs(piles, 0, 1);
        return (net + total) / 2;
    }
};