// T: O(n^3)
// S: O(n^2)
class Solution {
public:
    vector<vector<int>> memo;
    // max coins by bursting between left and right
    int dfs(int left, int right, vector<int>& nums) {
        if (right - left == 1) {
            return 0;
        }

        if (memo[left][right] != -1) return memo[left][right];

        int maxcoins = 0;
        // pick last balloon to burst
        // k is the last balloon burst in (left, right),
        // so left and right are its remaining neighbors.
        for (int k = left + 1; k < right; k++) {
            int coins = dfs(left, k, nums) + 
                        dfs(k, right, nums) + 
                        // 1 * nums[k] * 1 after bursting all others
                        nums[left] * nums[k] * nums[right];
            maxcoins = max(maxcoins, coins);
        }

        return memo[left][right] = maxcoins;
    }


    int maxCoins(vector<int>& balloons) {
        int n = balloons.size() + 2;
        // arr padded with 1 at boundary
        vector<int> nums(n);
        nums[0] = 1;
        nums[n - 1] = 1;
        for (int i = 1; i < n - 1; i++) {
            nums[i] = balloons[i - 1];
        }

        memo.resize(n, vector<int>(n, -1));
        return dfs(0, n-1, nums);
    }
};

// finding first balloon to burst not possible, as neighbors change 
// for future/
// choose last balloon to burst, as after bursting neightbors (1,1)
// never change. 