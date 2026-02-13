# Group Anagrams
# https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;

        for (int i=0;i<strs.size();i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            map[sorted].push_back(strs[i]);
        }

        for (auto it: map) {
            res.push_back(it.second);
        }
        
        return res;

    }
};

// Time complexity : O (m*nlogn)

// Soln without sorting
// Time complexity : O (m*n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        
        for (string s: strs) {
            // vector<int> freq(26, 0);
            map<char, int> freq;
            for (char c: s) {
                freq[c]++;
            }

            string key = "";
            for (auto it: freq) {
                key += to_string(it.first) + to_string(it.second);
            }
            mp[key].push_back(s);

        }
        for (auto it: mp) {
            res.push_back(it.second);
        }
        
        return res;

    }
};


// using vector which has smaller constant time complexity (most optimal)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string &s : strs) {
            vector<int> count(26, 0);

            // Count characters
            for (char c : s) {
                count[c - 'a']++;
            }

            // Build key
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto &p : mp) {
            res.push_back(p.second);
        }

        return res;
    }
};