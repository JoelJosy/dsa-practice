// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/

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