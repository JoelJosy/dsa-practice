// Time O(n)
// Space O(1)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool inserted = false;

        for (vector<int>& curr: intervals) {
            // non overlapping and before new interval
            if (curr[1] < newInterval[0]) 
                res.push_back(curr);
            // if non overlapping but after interval
            else if (curr[0] > newInterval[1]) {
                if (!inserted) {
                    res.push_back(newInterval);
                    inserted = true;
                }
                res.push_back(curr);
            }
            else {
                newInterval[0] = min(newInterval[0], curr[0]);
                newInterval[1] = max(newInterval[1], curr[1]);
            }
        }

        if (!inserted) res.push_back(newInterval);
        return res;
    }
};
