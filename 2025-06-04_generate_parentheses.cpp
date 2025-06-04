# Generate Parentheses
# https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", 0, 0, n, res);
        return res;
    }

    void backtrack(string curr, int open, int close, int n, vector<string> &res) {
        if (curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if (open < n) backtrack(curr + "(", open + 1, close, n, res);
        if (close < open) backtrack(curr + ")", open, close + 1, n, res);
    }
};