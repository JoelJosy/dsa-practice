// 200. No of islands
// https://leetcode.com/problems/number-of-islands/

// BFS
class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r + 1 < m && grid[r + 1][c] == '1') {
                q.push({r + 1, c});
                grid[r + 1][c] = '0';
            }
            if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                q.push({r - 1, c});
                grid[r - 1][c] = '0';
            }
            if (c + 1 < n && grid[r][c + 1] == '1') {
                q.push({r, c + 1});
                grid[r][c + 1] = '0';
            }
            if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                q.push({r, c - 1});
                grid[r][c - 1] = '0';
            }
            
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    bfs(grid, i, j ,m , n);
                }
            }
        }

        return islands;
    }
};


// DFS
// Smaller but might cause stack overflow for large grids

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        // base cases — out of bounds or already water
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return;

        grid[i][j] = '0';  // mark as visited

        // explore 4 directions
        dfs(grid, i + 1, j, m, n);  // down
        dfs(grid, i - 1, j, m, n);  // up
        dfs(grid, i, j + 1, m, n);  // right
        dfs(grid, i, j - 1, m, n);  // left
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return count;
    }
};