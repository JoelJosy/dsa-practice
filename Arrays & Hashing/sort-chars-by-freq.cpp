// Bucket sort
// T: O(n)
// S: O(n)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c: s) 
            freq[c]++;

        vector<vector<char>> bucket(s.size() + 1);

        for (auto& [c, f]: freq) {
            bucket[f].push_back(c);
        }

        string res = "";
        for (int i = s.size(); i >= 0; i--) {
            for (char c: bucket[i]) {
                res.append(i, c);
            }
        }
        return res;
    }
};

// Heap
// T: O(nlogk) k unique chars
// S: O(n)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c: s) 
            freq[c]++;

        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

        for (auto& [c, f]: freq) {
            pq.push({f, c});
        }

        string res = "";
        while (!pq.empty()) {
            auto [n, c] = pq.top(); pq.pop();
            res.append(n, c);
        }
        return res;
    }
};