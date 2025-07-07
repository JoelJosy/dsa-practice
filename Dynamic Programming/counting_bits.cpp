// 338 . Counting Bits
// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        int offset = 1;
        for (int i = 1; i <= n; i++) {
            if (offset * 2 == i) offset = i;
            dp[i] = 1 + dp[i - offset];
        }
        return dp;
    }
};

// 0 - 0000.  // 00
// 1 - 0001.  // 01
// 2 - 0010.  // 10
// 3 - 0011.  // 11
// 4 - 0100.  // 100.  // last two digits repeated + one more 1
// 5 - 0101.  // 101
// 6 - 0110.  // 110
// 7 - 0111.  // 111
// 8 - 1000.  // 1000.  // last three digits repeated + one more 1