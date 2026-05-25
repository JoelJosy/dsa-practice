// memoization
// O(n) for both time and space

class Solution {
public:
    int dfs(string& s, int i, unordered_map<int, int>& memo) {
        int n = s.size();
        if (i >= n) return 1;
        if (s[i] == '0') return memo[i] = 0;

        if (memo.find(i) != memo.end()) return memo[i];

        int onestep = dfs(s, i+1, memo);

        int twostep = 0;
        if (i+1 < n) {
            // substr is slow, use math
            int num = stoi(s.substr(i, 2));
            if (num <= 26 && num >= 10) {
                twostep = dfs(s, i+2, memo);
            }
        }
        
        return memo[i] = onestep+twostep;
    }

    int numDecodings(string s) {
        unordered_map<int, int> memo;
        int res = dfs(s, 0, memo);
        return res;
    }
};

// 1-26
// either take 1 digit or 2 digits

// tabulation
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 1);

        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            int onestep = dp[i+1];
            int twostep = 0;
            if (i+1 < n) {
                int num = (s[i]-'0')*10 +(s[i+1]-'0');
                if (num >= 10 && num <= 26) {
                    twostep = dp[i+2];
                }
            }
            dp[i] = onestep+twostep;
        }

        return dp[0];
    }
};

