// T: O(n) n -> length of string
// S: O(1) at most 26 chars in set

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }

        vector<int> res;
        int size = 0;
        int lastIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            size++;
            lastIndex = max(mp[s[i]], lastIndex);
            
            if (i == lastIndex) {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};

// My way

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }

        vector<int> res;

        int start = 0;

        while (start < s.size()) {
            int lastIndex = mp[s[start]];
            int i = start;

            while (i <= lastIndex) {
                lastIndex = max(lastIndex, mp[s[i]]);
                i++;
            }

            res.push_back(lastIndex - start + 1);
            start = lastIndex + 1;
        }

        return res;
    }
};