// 136. Single number
// https://leetcode.com/problems/single-number/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num: nums) {
            res = res ^ num;
        }
        return res;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// The solution uses the property of XOR where a number XORed with itself is 0 and
// a number XORed with 0 is the number itself. Thus, all numbers that appear
// twice will cancel each other out, leaving only the single number that appears once.