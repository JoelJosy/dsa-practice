// 417. Pacific Atlantic Water Flow
// https://leetcode.com/problems/pacific-atlantic-water-flow/

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
