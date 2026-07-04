// T: O(m * n)
// S: O(1)
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = order.size();
        int m = words.size();
        vector<int> rank(26, 0);

        for (int i = 0; i < n; i++) {
            rank[order[i] - 'a'] = i;
        }

        for (int i = 0; i < m - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int l1 = w1.size();
            int l2 = w2.size();
            if (l1 > l2 && w1.starts_with(w2))
                return false;

            for (int j = 0; j < min(l1, l2); j++) {
                if (w1[j] != w2[j]) {
                    if (rank[w1[j] - 'a'] > rank[w2[j] - 'a']) 
                        return false;
                    break;
                }
            }
        }
        return true;
    }
};