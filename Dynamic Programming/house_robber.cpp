// 198. House Robber
// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        if (nums.size() == 1) return nums[0];

        // most amt at house 0, is to just rob it
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            // if u dont rob, max is same as previous step
            // if robbed, max is loot + max of 2 steps behind
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }

        return dp[nums.size() - 1];
    }
};

// Space optimized
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int num : nums) {
            int curr = max(prev1, num + prev2);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};