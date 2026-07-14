// Top Down
// T: O(m*n)
// S: O(m*n)
class Solution {
public:
    int m, n;
    vector<vector<int>> memo;
    bool dfs(int i, int j, string& s, string& p) {
        if (j == n) return i == m;

        if (memo[i][j] != -1) return memo[i][j];

        bool match = i < m && (s[i] == p[j] || p[j] == '.');
        
        if (j + 1 < n && p[j+1] == '*') {
            // skip x*
            bool skip = dfs(i, j+2, s, p);
            // consume char
            bool take = match && dfs(i+1, j, s, p);
            return memo[i][j] = skip || take;
        } 

        if (match) {
            return memo[i][j] = dfs(i+1, j+1, s, p);
        }
        return memo[i][j] = false;
    }

    bool isMatch(string s, string p) {
        m = s.size();
        n = p.size();
        memo.resize(m+1, vector<int>(n+1, -1));
        return dfs(0, 0, s, p);
    }
};