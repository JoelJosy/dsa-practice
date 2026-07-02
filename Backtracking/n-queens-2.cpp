// T: O(N!)
// S: O(N)
class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> diag;
    unordered_set<int> antiDiag;
    int res = 0;

    bool isSafe(int r, int c) {
        return !(cols.count(c) || 
        diag.count(r - c) || 
        antiDiag.count(r + c));
    }

    void dfs(int row, int n) {
        if (row == n) {
            res++;
            return;
        } 

        for (int col = 0; col < n; col++) {
            if (!isSafe(row, col)) continue;

            cols.insert(col);
            diag.insert(row - col);
            antiDiag.insert(row + col);

            dfs(row + 1, n);

            cols.erase(col);
            diag.erase(row - col);
            antiDiag.erase(row + col);
        }
    }

    int totalNQueens(int n) {
        dfs(0, n);
        return res;
    }
};