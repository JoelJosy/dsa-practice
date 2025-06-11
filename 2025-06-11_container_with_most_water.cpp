# Container With Most Water
# https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l, r, area;
        int n = height.size();
        int maxArea = 0;
        l = 0;
        r = n - 1;
        while (l < r) {
            area = (r - l) * min(height[l], height[r]);
            if (area > maxArea) {
                maxArea = area;
                (height[l] < height[r]) ? l++ : r--;
            } else
            (height[l] < height[r]) ? l++ : r--;
        }
        return maxArea;
    }
};