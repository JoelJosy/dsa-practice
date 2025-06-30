// Missing number
// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int given_sum = 0;
        int real_sum = 0;
        for (int num: nums) {
            given_sum += num;
        }
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            real_sum += i;
        }

        return (real_sum - given_sum);
    }
};