// 1200. Minimum Absolute Difference
// https://leetcode.com/problems/minimum-absolute-difference/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end()); // sort array to use sliding window

        // find min diff
        int min_diff = INT_MAX;
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int diff = sorted[i] - sorted[i-1];
            min_diff = min(min_diff, diff);
        }

        // collect valid pairs
        for (int i = 1; i < n; i++) {
            if (sorted[i] - sorted[i-1] == min_diff) {
                res.push_back({sorted[i - 1], sorted[i]});
            }
        }
        return res;
    }
};