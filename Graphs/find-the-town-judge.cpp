// T: O(V+E)
// S: O(V)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1, 0);
        vector<int> out(n + 1, 0);

        for (auto& t: trust) {
            int ai = t[0];
            int bi = t[1];
            out[ai]++;
            in[bi]++;
        }

        for (int i = 1; i <= n; i++) {
            if (out[i] == 0 && in[i] == n - 1) 
                return i;
        }
        return -1;
    }
};