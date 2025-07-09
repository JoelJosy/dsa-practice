// 77 Combinations
// https://leetcode.com/problems/combinations/

class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int>& subset,
                                int n, int k, int start) {
        if (subset.size() == k) {
            res.push_back(subset);
            return;
        }
        for (int i = start; i <= n; i++) {
            subset.push_back(i);
            backtrack(res, subset, n, k, i+1);
            subset.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(res, subset, n, k, 1);
        return res;
    }
};