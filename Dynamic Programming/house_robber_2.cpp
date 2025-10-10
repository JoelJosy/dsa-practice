// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/description/

class Solution {
public:
    vector<int> memo;

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0]; // Edge case

        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());

        return max(rob_arr(nums1), rob_arr(nums2));
    }

    int rob_arr(vector<int>& nums) {
        // resize doesnt work cuz it leaves alr initialized
        // values untouched. Assign fn reassigns all values
        memo.assign(nums.size(), -1);  
        return dfs(nums, 0);
    }

    int dfs(vector<int>& nums, int i) {
        if (i >= nums.size()) return 0;
        if (memo[i] != -1) return memo[i];

        return memo[i] = max(dfs(nums, i + 1), nums[i] + dfs(nums, i + 2));
    }
};