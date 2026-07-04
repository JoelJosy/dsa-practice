// T: O(n^3)
// S: O(n)
// n -> length of string s
class Solution {
public:
    int dfs(int i, string& s, unordered_set<string>& dict, vector<int>& dp) {
        if (i == s.size()) return 0;
        if (dp[i] != -1) return dp[i];

        // skip char, add count of extra
        int res = 1 + dfs(i + 1, s, dict, dp); 

        string curr = "";
        for (int j = i; j < s.size(); j++) {
            curr.push_back(s[j]);
            if (dict.count(curr)) {
                res = min(res, dfs(j + 1, s, dict, dp));
            }
        }

        return dp[i] = res;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp(s.size(), -1);
        return dfs(0, s, dict, dp);
    }
};