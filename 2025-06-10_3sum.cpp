# 3Sum
# https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, j, k, target;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (i = 0; i < nums.size(); i++) {
            // skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            target = -nums[i];
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    // skip duplicate j and k
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] < target) j++;
                else k--;

            }
        }
        return res;
    }
};