// 39 Combination Sum
// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void backtrack(vector<int>& nums, int target, int i,
            vector<int>& subset, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        if (target < 0 || i >= nums.size()) return;

        subset.push_back(nums[i]);
        backtrack(nums, target-nums[i], i, subset, res);
        subset.pop_back();
        backtrack(nums, target, i+1, subset, res);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(candidates, target, 0, subset, res);
        return res;
    }
};