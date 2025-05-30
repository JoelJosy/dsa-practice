# Group Anagrams
# https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> map;

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