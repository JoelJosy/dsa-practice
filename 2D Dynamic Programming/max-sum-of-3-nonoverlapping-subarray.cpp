// 3 pointer soln
// T: O(n)
// S: O(1)
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int w1 = 0, w2 = 0, w3 = 0;

        int best1 = INT_MIN;
        int best1Idx = 0;

        int best2 = INT_MIN;
        vector<int> best2Idx(2);

        int best3 = INT_MIN;
        vector<int> ans(3);

        for (int i = 0; i <= n - 3 * k; i++) {

            // initialize / slide windows
            if (i == 0) {
                for (int j = 0; j < k; j++) {
                    w1 += nums[j];
                    w2 += nums[k + j];
                    w3 += nums[2 * k + j];
                }
            } 
            else {
                w1 += nums[i + k - 1];
                w1 -= nums[i - 1];

                w2 += nums[i + 2 * k - 1];
                w2 -= nums[i + k - 1];

                w3 += nums[i + 3 * k - 1];
                w3 -= nums[i + 2 * k - 1];
            }


            // best first window
            if (w1 > best1) {
                best1 = w1;
                best1Idx = i;
            }

            // best two windows
            if (best1 + w2 > best2) {
                best2 = best1 + w2;
                best2Idx = {best1Idx, i + k};
            }

            // best three windows
            if (best2 + w3 > best3) {
                best3 = best2 + w3;
                ans = {best2Idx[0], best2Idx[1], i + 2*k};
            }
        }

        return ans;
    }
};

// DP
// T: O(n)
// S: O(n)
class Solution {
public:
    vector<int> res;
    vector<vector<int>> memo;
    vector<int> windowSum;
    int n;
    int dfs(int i, int arrs, int k) {
        if (arrs == 0) return 0;
        if (i > n - k) return INT_MIN;

        if (memo[i][arrs] != INT_MAX) return memo[i][arrs];

        int skip = dfs(i+1, arrs, k);
        int take = windowSum[i] + dfs(i+k, arrs-1, k);

        return memo[i][arrs] = max(take, skip);
    }

    void build(int i, int remaining, int k) {
        if (remaining == 0 || i > n - k)
            return;

        int skip = dfs(i + 1, remaining, k);
        int take = windowSum[i] + dfs(i + k, remaining - 1, k);

        if (take >= skip) {          // tie -> take for lexicographically smallest
            res.push_back(i);
            build(i + k, remaining - 1, k);
        } else {
            build(i + 1, remaining, k);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        n = nums.size();
        memo.resize(n, vector<int>(4, INT_MAX));
        windowSum.resize(n - k + 1, 0);
        
        int sum = 0;
        // first window
        for (int i = 0; i < k; i++)
            sum += nums[i];
        windowSum[0] = sum;

        // remaining windows
        for (int i = k; i < n; i++) {
            sum += nums[i];
            sum -= nums[i-k];
            windowSum[i-k+1] = sum;
        }

        dfs(0, 3, k);
        build(0, 3, k);
        return res;
    }
};