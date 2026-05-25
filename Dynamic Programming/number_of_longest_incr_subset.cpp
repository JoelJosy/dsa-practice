// Optimal Tabulation
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        // index: {length of LIS, count of LIS}
        unordered_map<int, pair<int, int>> dp; 
        for (int i = n - 1; i >= 0; i--) {
            // default if rest all skipped
            int ilen = 1;
            int icount = 1;

            for (int j = i+1; j < n; j++) {
                if (nums[i] < nums[j]) {
                    auto [jlen, jcount] = dp[j];

                    if (ilen < jlen+1) {
                        // if better length, set new best length and new count
                        ilen = jlen+1;
                        icount = jcount;
                    } else if (ilen == jlen+1) {
                        // if same lis length, increment count 
                        // to include new path as well
                        icount += jcount;
                    }
                }
            }
            dp[i] = {ilen, icount};
        }
        
        int maxlen = 0;
        for (auto [i, p]: dp) maxlen = max(maxlen, p.first);

        int maxcount = 0;
        for (auto [i, p]: dp) {
            if (p.first == maxlen) maxcount += p.second;
        }
        return maxcount;
    }
};


// Memoization (Recursive overhead)
class Solution {
public:
    // memo: index, prev -> length, count
    pair<int,int> dfs(vector<int>& nums, int i, int prevIndex, vector<vector<pair<int,int>>>& memo) {
        if (i == nums.size()) {
            return {0, 1};
        }
        
        if (memo[i][prevIndex+1].first != -1) {
            return memo[i][prevIndex+1];
        }

        // leave it
        auto [skiplen, skipcount] = dfs(nums, i+1, prevIndex, memo);

        // take it
        int takelen = 0;
        int takecount = 0;
        if (prevIndex == -1 || nums[i] > nums[prevIndex]) {
            auto [nextlen, nextcount] = dfs(nums, i+1, i, memo);
            takelen = 1+nextlen;
            takecount = nextcount;
        }

        pair<int, int> ans;

        if (takelen > skiplen) {
            ans = {takelen, takecount};
        } else if (skiplen > takelen) {
            ans = {skiplen, skipcount};
        } else {
            // check if cant take
            if (takelen == 0) {
                ans = {skiplen, skipcount};
            } else ans = {takelen, takecount+skipcount};
        }

        return memo[i][prevIndex + 1] = ans;
    }

    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<pair<int,int>>> memo(nums.size(), vector<pair<int,int>>(nums.size()+1, {-1, -1})); 
        auto [len, count] = dfs(nums, 0, -1, memo);
        return count;
    }
};