// T: O(n^2)
// S: O(n^2)
class Solution {
public:
    int dfs(vector<int>& piles, int l, int r, vector<vector<int>>& memo) {
        if (l > r) {
            return 0;
        }

        if (memo[l][r] != 0) {
            return memo[l][r];
        }

        int score1 = piles[l];
        int score2 = piles[r];
        
        score1 -= dfs(piles, l+1, r, memo);
        score2 -= dfs(piles, l, r-1, memo);

        return memo[l][r] = max(score1, score2);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));

        int res = dfs(piles, 0, n - 1, memo);
        if (res > 0) return true;
        return false;
    }
};