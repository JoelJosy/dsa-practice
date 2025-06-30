// 977 squares of sorted array
// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> res(r+1, 0);
        int i = r;
        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) {
                res[i] = nums[l] * nums[l];
                l++;
                i--;
            } else {
                res[i] = nums[r] * nums[r];
                r--;
                i--;
            }
        }
        return res;
    }
};