// Time: O(m*n*4^length)
// Space: O(length)

class Solution {
public:
    // check if dfs works from board[r][c]
    // true if matches word[start...n]
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int start) {
        int m = board.size();
        int n = board[0].size();

        if (word[start] != board[r][c]) return false; // mismatch
        if (start == word.size() - 1) return true; // all matched

        // mark visited
        char ch = board[r][c];
        board[r][c] = '#';

        // expand 4 directions
        if (r+1 < m) {
            if (dfs(board, word, r+1, c, start+1)) {
                board[r][c] = ch;
                return true;
            }
        }
        if (c+1 < n) {
            if (dfs(board, word, r, c+1, start+1)) {
                board[r][c] = ch;
                return true;
            }
        }
        if (r-1 >= 0) {
            if (dfs(board, word, r-1, c, start+1)) {
                board[r][c] = ch;
                return true;
            }
        }
        if (c-1 >= 0) {
            if (dfs(board, word, r, c-1, start+1)) {
                board[r][c] = ch;
                return true;
            }
        }
        
        board[r][c] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};


// find positions of start letter
// for each, do dfs in all 4 directions until valid


// Cleaner
bool dfs(vector<vector<char>>& board, string& word, int r, int c, int start) {
    if (start == word.size()) return true;
    if (word[start] != board[r][c]) return false;

    int m = board.size(), n = board[0].size();
    char ch = board[r][c];
    board[r][c] = '#';

    int dr[] = {1, -1, 0, 0};
    int dc[] = {0,  0, 1, -1};
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
            if (dfs(board, word, nr, nc, start+1)) {
                board[r][c] = ch;  // restore before bubbling up
                return true;
            }
        }
    }

    board[r][c] = ch;
    return false;
}