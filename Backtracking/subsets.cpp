// 78 Subsets
// https://leetcode.com/problems/subsets/

class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& nums, 
                                vector<int>& subset, int index) {
                                    
        res.push_back(subset);
        for (index; index < nums.size(); index++) {
            subset.push_back(nums[index]); // include
            backtrack(res, nums, subset, index+1); // explore
            subset.pop_back(); // exclude
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(res, nums, subset, 0);
        return res;
    }
};