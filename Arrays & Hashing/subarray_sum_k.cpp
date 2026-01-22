// https://leetcode.com/problems/subarray-sum-equals-k/submissions/1893043110/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        unordered_map<int, int> map; // prefSum, freq
        map[0]=1;

        int count = 0;
        for (int num: nums) {
            prefixSum += num;

            int reqSubSum = prefixSum - k;
            if (map.count(reqSubSum)){
                count += map[reqSubSum];
            } 
            map[prefixSum]++;
        }

        return count;
    }
};