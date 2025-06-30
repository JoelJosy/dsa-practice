# Evaluate Reverse Polish Notation
# https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        unordered_set<string> ops = {"+", "-", "*", "/"};
        for (const string& token : tokens) {
            if (ops.count(token)) {
                int n1 = stk.top(); stk.pop();
                int n2 = stk.top(); stk.pop();
                if (token == "+") stk.push(n2 + n1);
                else if (token == "-") stk.push(n2 - n1);
                else if (token == "*") stk.push(n2 * n1);
                else if (token == "/") stk.push(n2 / n1);
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};