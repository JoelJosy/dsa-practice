// Optimal Binsearch
// T: O(n*log(total))
// S: O(1)
class Solution {
public:
    bool splitPossible(vector<int>& nums, int maxsum, int splits) {
        int currsplits = 0;
        int currsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (currsum + nums[i] <= maxsum) {
                currsum += nums[i];
            } else {
                currsum = nums[i];
                currsplits++;
                if (currsplits > splits) 
                    return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int splits = k - 1;

        int l = *max_element(nums.begin(), nums.end());
        // largest possible sum of subarray is total
        int r = accumulate(nums.begin(), nums.end(), 0);
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (splitPossible(nums, mid, splits)) {
                r = mid;
            } else 
                l = mid + 1;
        }
        return l;
    }
};


// Memoized DP
// T: O(n^2 * k)
// S: O(n * k)

class Solution {
public:
    vector<vector<int>> memo;

    int dfs(int idx, int k, vector<int>& nums, vector<int>& prefix) {
        int n = nums.size();

        // Last group: everything remaining is one subarray
        if (k == 1) {
            return prefix[n] - prefix[idx];
        }

        if (memo[idx][k] != -1)
            return memo[idx][k];

        int ans = INT_MAX;
        int currSum = 0;

        // Need at least k-1 elements after this cut
        for (int i = idx; i <= n - k; i++) {
            currSum += nums[i];

            // Remaining k-1 subarrays start from i+1
            int remaining = dfs(i + 1, k - 1, nums, prefix);

            int largest = max(currSum, remaining);

            ans = min(ans, largest);
        }

        return memo[idx][k] = ans;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        memo.assign(n, vector<int>(k + 1, -1));

        return dfs(0, k, nums, prefix);
    }
};