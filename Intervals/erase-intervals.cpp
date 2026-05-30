// Time: O(n)
// Space: O(n) output

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& rem) {
        vector<vector<int>> res;

        for (auto &curr : intervals) {

            // NO overlap → keep whole interval
            if (curr[1] <= rem[0] || curr[0] >= rem[1]) {
                res.push_back(curr);
            }

            else {
                // LEFT overlap → keep left part
                if (curr[0] < rem[0]) {
                    res.push_back({curr[0], rem[0]});
                }

                // RIGHT overlap → keep right part
                if (curr[1] > rem[1]) {
                    res.push_back({rem[1], curr[1]});
                }
            }
        }

        return res;
    }
};