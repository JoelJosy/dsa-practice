// Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_freq;
        unordered_map<char, int> win_freq;

        // Get char frequency of t
        for (char c : t) {
            t_freq[c]++;
        }

        int required = t_freq.size();  // number of unique chars to match
        int matched = 0;

        int left = 0, right = 0;
        int min_len = INT_MAX, min_start = 0;

        while (right < s.size()) {
            char rchar = s[right];
            win_freq[rchar]++;

            if (t_freq.count(rchar) && win_freq[rchar] == t_freq[rchar]) {
                matched++;
            }

            // Contract the window from the left
            while (matched == required) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }

                char lchar = s[left];
                win_freq[lchar]--;
                if (t_freq.count(lchar) && win_freq[lchar] < t_freq[lchar]) {
                    matched--;
                }
                left++;
            }

            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};