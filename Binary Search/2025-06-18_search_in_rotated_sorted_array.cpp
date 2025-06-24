# Search in Rotated Sorted Array
# https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int binSearch(int target, vector<int>& nums, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else return mid;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else if (nums[mid] < nums[r]) {
                r = mid;
            }
        }
        mid = l;
        l = 0;
        r = n - 1;
        int second = binSearch(target, nums, mid, r);
        int first = binSearch(target, nums, l, mid - 1);
        
        int ans = (first == -1) ? second : first;

        return ans;
    }
};
