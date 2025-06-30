// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/submissions/1681196870/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> map;
        for (int i = 0; i < sorted.size(); i++) {
            if (map.count(sorted[i])) continue;
            map[sorted[i]] = i;
        }
        for (int num: nums) {
            res.push_back(map[num]);
        }

        return res;
    }
};