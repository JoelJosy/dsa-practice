// Time: O(n)
// Space: O(n)

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> lstk; // indices of (
        stack<int> astk; // indices of *

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') lstk.push(i);
            else if (c == '*') astk.push(i);
            else {
                if (!lstk.empty()) lstk.pop();
                else if (!astk.empty()) astk.pop();
                else return false;
            }
        }

        // Each remaining '(' needs a '*' that comes AFTER it
        while (!lstk.empty() && !astk.empty()) {
            int lIdx = lstk.top(); lstk.pop();
            int aIdx = astk.top(); astk.pop();
            if (aIdx < lIdx) return false; // * is to the left of (, can't close it
        }

        return lstk.empty();
    }
};

// Space Optimized Greed
// Space: O(1)

class Solution {
public:
    bool checkValidString(string s) {
        int leftmin = 0; // min unmatched (
        int leftmax = 0; // max unmatched (

        // ( increases left count
        // ) decreases left count
        // * can do both

        for (char c: s) {
            if (c == '(') {
                leftmin++;
                leftmax++;
            } else if (c == ')') {
                leftmin--;
                leftmax--;
            } else {
                leftmin--; // treat * as ) -> best case
                leftmax++; // treat * as ( -> worst case
            }

            if (leftmin < 0) leftmin=0;
            if (leftmax < 0) return false;
        }

        return leftmin == 0;
    }
};