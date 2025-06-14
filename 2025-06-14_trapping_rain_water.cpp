# Trapping Rain Water
# https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int n = height.size();
        int lmax = 0;
        int rmax = 0;

        int l = 0;
        int r = n - 1;
        
        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if (lmax < rmax) {
                water += lmax - height[l];
                l++;
            } else {
                water += rmax - height[r];
                r--;
            }
        }
        return water;
    }
};
