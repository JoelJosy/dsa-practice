# Longest Consecutive Sequence
# https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int count, current;
        int maxCount=0;

        for (int num: numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                count = 1;
                current = num;
                while (numSet.find(current + 1) != numSet.end()) {
                    count++;
                    current++;
                }
                maxCount = max(maxCount, count);

            } else count = 1;
        }
        return maxCount;
};
};