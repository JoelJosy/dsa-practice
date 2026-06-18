// In place swapping
// T: O(n * n!)
// S: O(n * n) recursion + set
class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> used;
        for (int i = idx; i < nums.size(); i++) {
            if (used.count(nums[i])) continue;
            used.insert(nums[i]);

            swap(nums[i], nums[idx]);
            backtrack(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};