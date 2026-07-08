// T: O(n^2 * 2^n)
// S: O(n * 2^n)
class Solution {
public:
    unordered_set<string> dict;
    // start -> all valid sentences for s.substr(start)
    unordered_map<int, vector<string>> memo; 

    vector<string> dfs(string& s, int start) {
        if (start == s.size()) return {""};     
        if (memo.count(start)) return memo[start];

        vector<string> result;
        for (int i = start; i < s.size(); i++) {
            string word = s.substr(start, i - start + 1);
            if (dict.count(word)) {
                vector<string> rest = dfs(s, i + 1);
                for (string& r : rest) {
                    result.push_back(r.empty() ? word : word + " " + r);
                }
            }
        }
        memo[start] = result;
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s, 0);
    }
};