// Time O(nlogn)
// Space O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;

        for (int i = 0; i <= n; i++) {
            int x = i;
            int count = 0;

            while (x != 0) {
                count += x % 2;
                x /= 2;
            }

            res.push_back(count);
        }

        return res;
    }
};

// Time O(n)
// Space O(n)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }

        return dp;
    }
};