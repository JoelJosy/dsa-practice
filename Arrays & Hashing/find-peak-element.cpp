// T: O(logn)
// S: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid+1]) {
                // going downhill
                // peak must be at left
                r = mid;
            } else {
                // uphill
                // peak must be at right
                l = mid + 1;
            }
        }
        return l;
    }
};