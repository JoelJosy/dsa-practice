// T: O(m * n)
// S: O(m * n)
class Solution {
public:
    vector<pair<int, int>> dirns = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> dp;
    int dfs(int i, int j, vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (dp[i][j] != -1) return dp[i][j];

        int best = 1;
        for (auto& [r, c]: dirns) {
            int nr = i + r;
            int nc = j + c;
            if (nr >= m || nc >= n || nr < 0 || nc < 0) continue;

            if (matrix[i][j] < matrix[nr][nc]) {
                best = max(best, 1 + dfs(nr, nc, matrix));
            }
        }
        return dp[i][j] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        dp.resize(m, vector<int>(n, -1));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(i, j, matrix));
            }
        }
        return res;
    }
};


// Bottom up
// BFS + Kahns Topological
// Same complexity but no recursion
class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int longestIncreasingPath(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> indeg(m, vector<int>(n, 0));

        // build indegree
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto [dx, dy] : dir) {
                    int ni = i + dx, nj = j + dy;
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

                    if (mat[ni][nj] < mat[i][j]) {
                        indeg[i][j]++;
                    }
                }
            }
        }

        queue<pair<int,int>> q;

        // start from all minima
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (indeg[i][j] == 0) q.push({i,j});
            }
        }

        int length = 0;

        while (!q.empty()) {
            int sz = q.size();
            length++;

            while (sz--) {
                auto [i,j] = q.front(); q.pop();

                for (auto [dx, dy] : dir) {
                    int ni = i + dx, nj = j + dy;

                    if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

                    if (mat[ni][nj] > mat[i][j]) {
                        indeg[ni][nj]--;
                        if (indeg[ni][nj] == 0) {
                            q.push({ni,nj});
                        }
                    }
                }
            }
        }

        return length;
    }
};