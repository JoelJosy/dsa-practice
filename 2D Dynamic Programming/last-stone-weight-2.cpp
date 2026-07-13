// T: O(n * total)
// S: O(n * total)
class Solution {
public:
    int total = 0;
    int n;
    vector<vector<int>> dp;
    int dfs(vector<int>& stones, int psum, int i) {
        if (i == n) {
            return abs(2 * psum - total);
        }

        if (dp[psum][i] != INT_MAX) return dp[psum][i];

        // skip
        int skip = dfs(stones, psum, i+1);
        // add to sum
        int add = dfs(stones, psum + stones[i], i+1);
        int minpsum = min(skip, add);

        return dp[psum][i] = minpsum; 
    }
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        total = accumulate(stones.begin(), stones.end(), 0);
        // dp[psum][i]
        dp.resize(total + 1, vector<int>(n, INT_MAX));

        return dfs(stones, 0, 0);
    }
};

// split stones into 2 subsets, one +ve psum, and other -ve nsum
// minimize psum - nsum
// minimize => psum - (total - psum) => 2*psum - total


// Bottom up
// T: O(n * total)
// S: O(total)
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = accumulate(stones.begin(), stones.end(), 0);


        vector<int> next(total + 1); 
        vector<int> curr(total + 1);
        // for i = n, no stones left
        for (int psum = 0; psum <= total; psum++) {
            next[psum] =  abs(2 * psum - total);
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int psum = total; psum >=0; psum--) {
                int skip = next[psum];
                int add = INT_MAX;
                if (psum + stones[i] <= total)
                    add = next[psum + stones[i]];
                curr[psum] = min(skip, add);
            }
            next = curr;    
        }

        return next[0];
    }
};

// split stones into 2 subsets, one +ve psum, and other -ve nsum
// minimize psum - nsum
// minimize => psum - (total - psum) => 2*psum - total