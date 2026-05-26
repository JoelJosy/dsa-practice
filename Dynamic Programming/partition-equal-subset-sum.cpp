// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/

// Memoization
// O(n * target)
// O(n * target) + O(n) (FYI)
class Solution {
public:
    bool dfs(vector<int>& nums, int i, int rem,
             vector<vector<int>>& memo) {

        if (rem == 0) return true;
        if (i == nums.size() || rem < 0) return false;

        if (memo[i][rem] != -1)
            return memo[i][rem];

        bool take = dfs(nums, i + 1, rem - nums[i], memo);
        bool skip = dfs(nums, i + 1, rem, memo);

        return memo[i][rem] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2) return false;
        
        int target = sum / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
        return dfs(nums, 0, target, memo);
    }
};


// Space Optimized O(n)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }

        if (sum%2 != 0) return false;

        unordered_set<int> dp;
        dp.insert(0);

        int target = sum/2;
        for (int i = nums.size() - 1; i >=0; i--) {
            unordered_set<int> temp = dp;
            for (int t: dp) {
                if (t+nums[i] == target) return true;
                temp.insert(nums[i] + t);
            }
            dp = temp;
        }
        return false;
    }
};


// Tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) sum += x;

        if (sum % 2) return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(target + 1, false)
        );

        // sum 0 always possible
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int s = 1; s <= target; s++) {
                bool skip = dp[i-1][s];
                bool take = false;
                if (s >= nums[i-1]) {
                    take = dp[i-1][s - nums[i-1]];
                }

                dp[i][s] = take || skip;
            }
        }

        return dp[n][target];
    }
};