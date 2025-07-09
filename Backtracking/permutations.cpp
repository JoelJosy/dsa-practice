// 46 Permutations
// https://leetcode.com/problems/permutations/

// Neetcode way
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {{}};
        }
        
        vector<int> tmp = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permute(tmp);
        vector<vector<int>> res;

        for (auto &p: perms) {
            for (int i = 0; i <= p.size(); i++) {
                vector<int> p_copy = p;
                p_copy.insert(p_copy.begin() + i, nums[0]);
                res.push_back(p_copy);
            }
        }
        return res;
    }
};

// Optimal Way: (in place swaps)


class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, int index) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            backtrack(nums, index+1);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;    
    }
};
