// 53 MAximum Subarray
// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
        }

        return *max_element(dp.begin(), dp.end());

    }
};

// Kadane's improved space complexity

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;

    }
};

class Solution {
public:
    vector<int> maxSubArrayWithArray(vector<int>& nums) {
        int maxSum = nums[0], currSum = 0;
        int start = 0, end = 0, tempStart = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (currSum <= 0) {
                // start new subarray
                currSum = nums[i];
                tempStart = i;
            } else {
                currSum += nums[i];
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                start = tempStart;  // record start of max subarray
                end = i;            // record end of max subarray
            }
        }

        vector<int> res(nums.begin() + start, nums.begin() + end + 1);
        return res;
    }
};