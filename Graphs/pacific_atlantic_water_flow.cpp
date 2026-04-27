// 417. Pacific Atlantic Water Flow
// https://leetcode.com/problems/pacific-atlantic-water-flow/


class Solution {
public:
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<int>>& visited) {
        if (r<0 || c<0 || r>=heights.size() || c>=heights[0].size() || visited[r][c] == 1) {
            return;
        }
        visited[r][c] = 1;
        if (r+1 < heights.size() && heights[r][c] <= heights[r+1][c]) {
            dfs(heights, r+1, c, visited);
        }
        if (c+1 < heights[0].size() && heights[r][c] <= heights[r][c+1]) {
            dfs(heights, r, c+1, visited);
        }
        if (r-1 >=0 && heights[r][c] <= heights[r-1][c]) {
            dfs(heights, r-1, c, visited);
        }
        if (c-1 >=0 && heights[r][c] <= heights[r][c-1]) {
            dfs(heights, r, c-1, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0)); 
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // go row wise
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, pacific);
            dfs(heights, i, n-1, atlantic);
        }
        // go col wise
        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, pacific);
            dfs(heights, m-1, j, atlantic);
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};



class Solution {
public:
    void dfs(int r, int c, set<pair<int,int>>& ocean, int prevHeight, vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS) return;
        if (heights[r][c] < prevHeight) return;
        if (ocean.count({r,c})) return;

        ocean.insert({r, c});

        dfs(r+1, c, ocean, heights[r][c], heights);
        dfs(r-1, c, ocean, heights[r][c], heights);
        dfs(r, c+1, ocean, heights[r][c], heights);
        dfs(r, c-1, ocean, heights[r][c], heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        set<pair<int,int>> atl, pac; // row, col 

        for (int c = 0; c < COLS; c++) {
            dfs(0, c, pac, heights[0][c], heights);
            dfs(ROWS-1, c, atl, heights[ROWS-1][c], heights);
        }

        for (int r = 0; r < ROWS; r++) {
            dfs(r, 0, pac, heights[r][0], heights);
            dfs(r, COLS-1, atl, heights[r][COLS-1], heights);
        }

        vector<vector<int>> res;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (atl.count({r,c}) && pac.count({r,c})) {
                    res.push_back({r,c});
                }
            }
        }

        return res;
    }
};
