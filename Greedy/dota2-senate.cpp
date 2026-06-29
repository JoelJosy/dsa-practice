// T: O(n)
// S: O(n)
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> qr;
        queue<int> qd;

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') qr.push(i);
            else qd.push(i);
        }

        while (!qr.empty() && !qd.empty()) {
            if (qr.front() < qd.front()) {
                // Radiant turn, push to end of queue (cyclic)
                int curr = qr.front(); qr.pop();
                qr.push(curr + n);

                // ban next Dire
                qd.pop();
            } else {
                int curr = qd.front(); qd.pop();
                qd.push(curr + n);
                qr.pop();
            }
        }

        return (qr.size() == 0) ? "Dire" : "Radiant";
    }
};