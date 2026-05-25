// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/

// Optimal Son: Binsearch
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int num: nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
        }

        return tails.size();
    }
};
// O(nlogn) 

// Memoization
class Solution {
public:
    // index, prev -> count
    int dfs(vector<int>& nums, int i, int prevIndex, vector<vector<int>>& memo) {
        if (i == nums.size()) return 0;
        
        if (memo[i][prevIndex+1] != -1) {
            return memo[i][prevIndex+1];
        }

        // leave it
        int skip = dfs(nums, i+1, prevIndex, memo);

        // take it
        int take = skip;
        if (prevIndex == -1 || nums[i] > nums[prevIndex]) {
            take = 1 + dfs(nums, i+1, i, memo);
        }

        return memo[i][prevIndex+1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size()+1, -1)); 
        return dfs(nums, 0, -1, memo);
    }
};
// O(n^2)

// Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // When all processed, LIS is 0
        // dp[i][prevIndex] -> LIS count
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n-1; i >= 0; i--) {
            for (int prevIndex = i-1; prevIndex >= -1; prevIndex--) {
                // leave it
                int skip = dp[i+1][prevIndex+1];

                // take it
                int take = skip;
                if (prevIndex == -1 || nums[i] > nums[prevIndex]) {
                    take = 1 + dp[i+1][i+1];
                }

                dp[i][prevIndex+1] = max(take, skip);
            }
        }

        return dp[0][0];
    }
};
// O(n^2)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (nums[i] < nums[j]) {
                    //         skip j, take j
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};