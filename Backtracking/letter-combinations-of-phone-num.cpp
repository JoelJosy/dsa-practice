// T: O(n*4^n)
// S: O(n)
// n -> length of digits
class Solution {
public:
    vector<string> res = {};
    vector<string> digmap = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string& digits, int i, string& curr) {
        if (i == digits.size()) {
            res.push_back(curr);
            return;
        }

        int dig = digits[i] - '0';
        for (char c: digmap[dig]) {
            curr += c;
            backtrack(digits, i+1, curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string curr = "";
        backtrack(digits, 0, curr);
        return res;
    }
};
