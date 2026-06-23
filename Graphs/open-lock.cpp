// T: O(10^4 * 8)
// S: O(10^4)
class Solution {
public:
    unordered_set<string> invalid;
    unordered_set<string> visited;
    vector<string> getNeighbors(string curr) {
        vector<string> res;
        for (int i = 0; i < 4; i++) {
            char c = curr[i];
            
            string up = curr;
            string down = curr;
            if (c == '0') {
                up[i]++;
                down[i] = '9';
            } else if (c == '9') {
                up[i] = '0';
                down[i]--;
            } else {
                up[i]++;
                down[i] = down[i] - 1;
            }
            res.push_back(up);
            res.push_back(down);
        }
        return res;
    }

    int openLock(vector<string>& deadends, string target) {
        invalid.insert(deadends.begin(), deadends.end()); 
        if (invalid.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int count = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string curr = q.front(); q.pop();
                if (curr == target)
                    return count;

                for (string n: getNeighbors(curr)) {
                    if (!visited.count(n) && !invalid.count(n)) {
                        visited.insert(n);
                        q.push(n);
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
