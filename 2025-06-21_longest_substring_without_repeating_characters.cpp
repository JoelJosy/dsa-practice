# Longest Substring Without Repeating Characters
# https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxLen = 0;
        unordered_set<char> chars;

        while (r < s.size()) {
            if (chars.count(s[r])) {
                chars.erase(s[l]);
                l++;
            } else {
                chars.insert(s[r]);
                r++;
                maxLen = max(r - l, maxLen);
            }
        }

        return maxLen;
    }
};