// T: O(n*2^n)
// S: O(n*2^n)

class Solution {
public:
    vector<vector<string>> res;

    bool isPal(string &sub) {
        int l = 0, r = sub.size()-1;
        while (l < r) {
            if (sub[l] != sub[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(int i, string& s, vector<string>& curr) {
        if (i == s.size()) {
            res.push_back(curr);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            string sub = s.substr(i, j-i+1);
            if (isPal(sub)) {
                // include full partition
                curr.push_back(sub);
                backtrack(j+1, s, curr);
                // exclude
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr;
        backtrack(0, s, curr);
        return res;
    }
};
