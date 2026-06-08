// Optimal using bitmasking
// T: O(n!) 
// S: O(n)
// Row 0:   . Q . .      diag bits:     0100
// Row 1:   . . ? .      shifts right → 0010  (that position is now attacked)
class Solution {
public:
    vector<string> board;
    vector<vector<string>> res;

    void backtrack(int n, int row, int cols, int diag, int antiDiag) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        int free = ((1 << n) - 1) & ~(cols | diag | antiDiag);

        for (int col = 0; col < n; col++) {
            if (!(free & (1 << col))) continue;

            int bit = (1 << col);

            board[row][col] = 'Q';

            backtrack(
                n,
                row + 1,
                cols | bit,
                (diag | bit) << 1,
                (antiDiag | bit) >> 1
            );

            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board.assign(n, string(n, '.'));
        res.clear();

        backtrack(n, 0, 0, 0, 0);
        return res;
    }
};

// Better using Sets
// T: O(n!) 
// S: O(n^2)
class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> diag;
    unordered_set<int> antiDiag;

    bool isSafe(int row, int col) {
        if (cols.count(col) || diag.count(row - col) ||
            antiDiag.count(row + col)) {
                return false;
            }
        return true;
    }

    void backtrack(int n, vector<string>& curr, int row) {
        if (row == n) {
            res.push_back(curr);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!isSafe(row, col)) continue;

            // if safe, insert Q
            curr[row][col] = 'Q';
            cols.insert(col);
            diag.insert(row - col);
            antiDiag.insert(row + col);

            backtrack(n, curr, row+1);
            
            // skip cell
            curr[row][col] = '.';
            cols.erase(col);
            diag.erase(row - col);
            antiDiag.erase(row + col);
        }  
        
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n==2 || n==3) return {};
        if (n==1) return {{"Q"}};

        vector<string> curr(n, string(n, '.'));
        backtrack(n, curr, 0);
        return res;
    }
};


// T: O(n! * n) extra n for isSafe
// S: O(n^2)

class Solution {
public:
    vector<vector<string>> res;

    bool isSafe(int r, int c, vector<string>& curr) {
        for (int i = r - 1; i >= 0; i--) {
            if (curr[i][c] == 'Q') return false;
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (curr[i][j] == 'Q') return false;
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < curr.size(); i--, j++) {
            if (curr[i][j] == 'Q') return false;
        }
        return true;
    }

    void backtrack(int n, vector<string>& curr, int row) {
        if (row == n) {
            res.push_back(curr);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!isSafe(row, col, curr)) continue;

            // if safe, insert Q
            curr[row][col] = 'Q';

            backtrack(n, curr, row+1);
            
            // skip cell
            curr[row][col] = '.';
        }  
        
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n==2 || n==3) return {};
        if (n==1) return {{"Q"}};

        vector<string> curr(n, string(n, '.'));
        backtrack(n, curr, 0);
        return res;
    }
};
