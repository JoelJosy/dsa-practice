// T: O(L) (L -> final decoded string length = maxK * n)
// S: O(L)
class Solution {
public:
    string decodeString(string s) {
        // num, prev str
        stack<pair<int, string>> stk;
        int num = 0;
        string curr = "";

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                stk.push({num, curr});
                curr = "";
                num = 0;
            } else if (c == ']') {
                auto [k, prev] = stk.top();
                stk.pop();

                string temp = "";
                for (int i = 0; i < k; i++) 
                    temp += curr;
                curr = prev + temp;
            } else 
                curr += c;
        }

        return curr;
    }
};