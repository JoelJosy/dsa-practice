# Find Minimum in Rotated Sorted Array
# https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l)/2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else if (nums[mid] <= nums[r]) {
                r = mid;
            }
        }
        return nums[r];
    }
};