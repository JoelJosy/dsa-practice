// minTimeToVisitAllPoints
// https://leetcode.com/problems/minimum-time-visiting-all-points/

// Min time is: max of the absolute differences in x and y coordinates
// explanation:
// To move from point (x1, y1) to (x2, y2), you can either:
// 1. Move horizontally to x2, then vertically to y2
// 2. Move vertically to y2, then horizontally to x2
// In both cases, the time taken is max(|x2 - x1|, |y2 - y1|).
// This is because you can move diagonally, which allows you to cover both x and y differences simultaneously.
// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 1; i < points.size(); i++) {
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);
            res += max(dx, dy);
        }
        return res;
    }
};
