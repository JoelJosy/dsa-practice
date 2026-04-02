class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<vector<int>>& res, vector<int>& subset) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {

            if (i-1>=start && candidates[i] == candidates[i-1]) continue;

            subset.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i+1, res, subset);
            subset.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, res, subset);
        return res;
    }
};
