class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<int, int> freq;
        for (char ch: s) {
            freq[ch]++;
        }

        for (auto p: freq) {
            pq.push({p.second, p.first});
        }

        string res = "";
        while (pq.size() >= 2) {
            auto [f1, c1] = pq.top(); pq.pop();
            auto [f2, c2] = pq.top(); pq.pop();
            res += c1;
            res += c2;
            if (--f1 > 0) pq.push({f1, c1});
            if (--f2 > 0) pq.push({f2, c2});
        }

        if (!pq.empty()) {
            auto [f, c] = pq.top();
            if (f > 1) return ""; // impossible
            res += c;
        }
        
        return res;
    }
};