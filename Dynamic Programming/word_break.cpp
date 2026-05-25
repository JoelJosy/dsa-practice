// memoization
// Time: O(n*m*n) where n->len(s), and m->len(wordDict)
// Space: O(n)
class Solution {
public:
    bool dfs(int i, string& s, vector<string>& wordDict, vector<int>& memo) {
        if (i == s.size()) return true;
        if (memo[i] != -1) return memo[i];

        for (string& w: wordDict) {
            if (i+w.size() <= s.size() && s.substr(i, w.size()) == w) {
                if (dfs(i + w.size(), s, wordDict, memo)) {
                    return memo[i] = true;
                }
            }
        }
        return memo[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        return dfs(0, s, wordDict, memo);
    }
};


// tabulation
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int slen = s.size();
        vector<bool> dp(slen+1, false);
        dp[slen] = true;

        for (int i = s.size()-1; i>=0; i--) {
            for (string& w: wordDict) {
                int wlen = w.size();
                if (i + wlen <= slen && s.substr(i, wlen) == w) {
                    if (dp[i+wlen]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[0];
    }
};