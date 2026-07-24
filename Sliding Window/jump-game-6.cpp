// T: O(n)
// S: O(n)
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);

        deque<int> dq;
        
        dp[0] = nums[0];
        dq.push_back(0);
        for (int i = 1; i < n; i++) {
            // evict out of window vals
            while (!dq.empty() && dq.front() < i - k)
                dq.pop_front();

            dp[i] = nums[i] + dp[dq.front()];

            while (!dq.empty() && dp[i] > dp[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return dp[n-1];
    }
};

// dp[i] = max score at i
// for k = 3, 
// dp[6] = nums[6] + max(dp[3], dp[4], dp[5])
// dp[5] = nums[5] + max(dp[2], dp[3], dp[4])
// dp[4] = nums[4] + max(dp[1], dp[2], dp[3])
// similar to sliding window max