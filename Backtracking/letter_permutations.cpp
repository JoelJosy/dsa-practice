// 784 Letter Case Permutation
// https://leetcode.com/problems/letter-case-permutation/description/


class Solution {
public:

    void backtrack(vector<string> &arr, string input, string remaining) {
        if (input.empty()) {
            arr.push_back(remaining);
            return;
        }

        char ch = input[0];
        input.erase(0,1);

        if (isdigit(ch)) backtrack(arr, input, remaining+ch);
        else {
            backtrack(arr, input, remaining+(char)tolower(ch));
            backtrack(arr, input, remaining+(char)toupper(ch));
        }

    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        backtrack(res, s, "");
        return res;
    }
};