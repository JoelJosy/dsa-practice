// 2672. Number of Adjacent Elements With the Same Color
// https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/description/

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> line(n, 0);
        vector<int> res;
        int count = 0;
        for (auto& q: queries) {
            int idx = q[0];
            int col = q[1];
            
            if (idx-1>=0 && line[idx-1]!=0 && line[idx-1] == line[idx]) count--;
            if (idx+1<n && line[idx+1] != 0 && line[idx+1] == line[idx]) count--;

            line[idx] = col;
            
            if (idx-1>=0 && line[idx-1] == line[idx]) count++;
            if (idx+1<n && line[idx+1] == line[idx]) count++;
            res.push_back(count);
        }
        return res;
    }
};