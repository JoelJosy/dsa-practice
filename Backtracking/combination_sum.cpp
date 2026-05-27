// 39 Combination Sum
// https://leetcode.com/problems/combination-sum/

// Time: O(2^(T/M))
// Space: O(T/M)
// N = number of candidates
// T = target
// M = minimum element in nums

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

// using for loop 
// Time: O(N^(T/M))
class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int target, vector<int>& currpath, int i) {
        if (target == 0) {
            res.push_back(currpath);
            return;
        }
        if (target < 0 || i == nums.size()) return;
        
        // check only nums that havent been used for unique combinations
        for (i; i < nums.size(); i++) {
            currpath.push_back(nums[i]);
            // not i+1 as we can reuse nums[i]
            backtrack(nums, target-nums[i], currpath, i);
            currpath.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> currpath;
        backtrack(nums, target, currpath, 0);
        return res;
    }
};
