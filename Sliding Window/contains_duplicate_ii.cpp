// 219. Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map; // num, index
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(nums[i]) && abs(i-map[nums[i]]) <= k ) {
                return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};