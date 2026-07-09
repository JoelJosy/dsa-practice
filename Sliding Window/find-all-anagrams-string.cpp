// T: O(n)
// S: O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int m = s.size();
        int n = p.size();

        vector<int> target(26, 0);
        for (char c: p) 
            target[c - 'a']++;

        vector<int> window(26, 0);
        int r = 0;
        while (r < m) {
            int l = r - n + 1;
            if (r < n) l = 0;

            window[s[r] - 'a']++;

            if (window == target) {
                res.push_back(l);
            } 

            if (r >= n - 1) {
                window[s[l] - 'a']--;
            }

            r++;
        }
        return res;
    }
};