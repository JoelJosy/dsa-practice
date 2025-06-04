# Daily Temperatures
# https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int temp;
        vector<int> res(n,0);
        stack<int> unresolved;

        for (int i = 0; i < n; i++) {
            temp = temperatures[i];
            while (!unresolved.empty() && 
                    temp > temperatures[unresolved.top()]) 
            {
                int top = unresolved.top();
                unresolved.pop();
                int days = i - top;
                res[top] = days;
            }
            unresolved.push(i);

        }
        return res;
    }
};