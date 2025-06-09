# Largest Rectangle in Histogram
# https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        vector<int> prevSmall(n, 0);
        vector<int> nextSmall(n, 0);
        stack<int> stk;

        // Left Smaller
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            prevSmall[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();
        
        // Right Smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            nextSmall[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        // Final Check
        for (int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, heights[i] * 
                        (nextSmall[i] - prevSmall[i] - 1 ));
        }
    
        return maxArea;
    }
};