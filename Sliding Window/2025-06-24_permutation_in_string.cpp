# Permutation in String
# https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 > len2) return false;

        unordered_map<char, int>freq1;
        unordered_map<char, int>freq2;
        for (int i = 0; i < len1; i++) {
            freq1[s1[i]]++;
            freq2[s2[i]]++;
        } 

        if (freq1==freq2) return true;

        int l = 0;
        int r = len1;
        while (r < len2) {
            freq2[s2[l]]--;
            if (freq2[s2[l]] == 0) freq2.erase(s2[l]);
            l++;
            freq2[s2[r]]++;
            if (freq1==freq2) return true;
            r++;
        }

        return false;
    }
};