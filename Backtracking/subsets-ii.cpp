// Time: O(2^N)
// Space: O(2^N) since all states stored;

class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int start, vector<int>& subset) {
        res.push_back(subset);

        for (int i = start; i < nums.size(); i++) {
            if (i-1>=start && nums[i] == nums[i-1]) continue;

            subset.push_back(nums[i]);
            backtrack(nums, i+1, subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        backtrack(nums, 0, subset);
        return res;
    }
};