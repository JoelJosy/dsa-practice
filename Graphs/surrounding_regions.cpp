// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    int ROWS, COLS;

    void dfs(int r, int c, vector<vector<char>>& board) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != 'O') {
            return;
        }
        board[r][c] = '#'; 
        
        dfs(r+1, c, board);
        dfs(r-1, c, board);
        dfs(r, c+1, board);
        dfs(r, c-1, board);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            if (board[r][0] == 'O') dfs(r, 0, board);
            if (board[r][COLS-1] == 'O') dfs(r, COLS-1, board);
        }
        for (int c = 0; c < COLS; c++) {
            if (board[0][c] == 'O') dfs(0, c, board);
            if (board[ROWS-1][c] == 'O') dfs(ROWS-1, c, board);
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == '#') board[r][c] = 'O';
            }
        }
    }
};