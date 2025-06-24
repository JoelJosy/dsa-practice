# Valid Sudoku
# https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        string keyr, keyc, keyb;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char curr = board[i][j];
                if (curr != '.') {
                    keyr = string(1,curr) + "row" + to_string(i);
                    keyc = string(1,curr) + "col" + to_string(j);
                    keyb = string(1,curr) + "box" + to_string(i/3) + "-"
                         + to_string(j/3);

                    if (!seen.insert(keyr).second || !seen.insert(keyc).second
                        || !seen.insert(keyb).second) {
                        return false;
                    }
                }
            }
        }
        return true;

    }
};