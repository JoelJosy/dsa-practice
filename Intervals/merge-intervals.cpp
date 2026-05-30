// Time: O(nlogn)
// Space: O(n) output array 
//        O(1) extra space

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& curr = intervals[i];

            // overlapping
            if (curr[0] <= prev[1]) {
                prev[0] = min(prev[0], curr[0]);
                prev[1] = max(prev[1], curr[1]);
            }
            // non-overlapping
            else {
                res.push_back(prev);
                prev = curr;
            }
        }

        // push last interval
        res.push_back(prev);
        return res;
    }
};

// Time: O(nlogn)
// Space: O(n) output array 
// Only the last interval in the result can overlap with the current one.
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& prev = res.back();
            vector<int>& curr = intervals[i];

            if (curr[0] <= prev[1]) {
                // merge
                prev[1] = max(prev[1], curr[1]);
            } else {
                // push if non overlapping
                res.push_back(curr);
            }
        }

        return res;
    }
};
