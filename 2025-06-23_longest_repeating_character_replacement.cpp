# Longest Repeating Character Replacement
# https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0;
        int r = 0;
        int maxFreq = 0;
        int maxLen = 0;
        while (r < s.size()) {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);

            int windowLen = r - l + 1;
            int replacements = windowLen - maxFreq;

            if (replacements > k) {
                freq[s[l]]--;
                l++;
            } else {
                maxLen = max(maxLen, windowLen);
            }
            r++;
        }
        return maxLen;
    }
};
