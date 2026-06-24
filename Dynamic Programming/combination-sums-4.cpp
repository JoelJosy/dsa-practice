// DP
// T: O(t*n)
// S: O(t) 
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int t = 1; t <= target; t++) {
            for (int n: nums) {
                if (t - n >= 0) {
                    dp[t] += dp[t-n];
                }
            }
        }

        return (int)dp[target];
    }
};

// Memo
// T: O(t*n)
// S: O(t)
class Solution {
public:
    unordered_map<int, int> memo;
    int backtrack(vector<int>& nums, int target) {
        if (memo.count(target)) return memo[target];

        if (target == 0) {
            return 1;
        }

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target - nums[i] >= 0)
                count += backtrack(nums, target - nums[i]);
        }
        return memo[target] = count;
    }

    int combinationSum4(vector<int>& nums, int target) {
        return backtrack(nums, target);
    }
};

// Backtracking
// T: O(n^t)
// S: O(t)