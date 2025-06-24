# Valid Anagram
# https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m1;
        
        for (auto it : s) {
            m1[it]++;
        }

        for (auto it : t) {
            m1[it]--;
        }

        for (auto it : m1) {
            if (it.second != 0) {
                return false;
            }
        }

        return true;
    }
};