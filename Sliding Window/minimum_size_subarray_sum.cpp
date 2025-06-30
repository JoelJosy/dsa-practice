// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int l = 0;
        int r = l;
        int currSum = 0;
        while (r < nums.size()) {
            currSum += nums[r];
            while (currSum >= target) {
                minLen = min(minLen, r-l+1);
                currSum -= nums[l];
                l++;
            }
            r++;
        }


        if (minLen == INT_MAX) return 0;
        return minLen;
    }
};