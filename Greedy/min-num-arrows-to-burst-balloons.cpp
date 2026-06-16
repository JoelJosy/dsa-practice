// T: O(nlogn)
// S: O(1) auxilliary, O(logn) due to sorting stack
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort by end
        sort(points.begin(), points.end(), 
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int res = 1;
        // optimal shooting point
        int minend = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= minend) continue;
            minend = points[i][1];
            res++;
        }
        return res;
    }
};

// optimal point is min end of overlapping groups
// sorted by end:
// [1,6], [2,8], [7,12], [10,16]
// skip ones thats bursted