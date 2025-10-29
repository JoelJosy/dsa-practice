// 6. Zigzag Conversion
// https://leetcode.com/problems/zigzag-conversion/


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) 
            return s;

        bool goDown = true;
        int len = size(s);

        vector<vector<char>> table(numRows);
        int row = 0;
        for (char c: s) {
            table[row].push_back(c);
            if (row == 0) {
                goDown = true;
            } else if (row == numRows-1) {
                goDown = false;
            }

            if (goDown) {
                row++;
            } else {
                row--;
            }
        }

        string res;
        for (const auto& row: table) {
            for (char c: row) {
                res += c;
            }
        }
        return res;
    }
};