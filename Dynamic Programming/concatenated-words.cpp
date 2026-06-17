// Optimal that avoids substr
// T: O(N * L^2)
// S: O(N*L)
class Solution {
public:
    unordered_set<string_view> dict;
    unordered_map<string_view, bool> memo;

    bool canform(string_view w) {
        auto it = memo.find(w);
        if (it != memo.end()) return it->second;

        int n = w.size();

        for (int i = 1; i < n; i++) {
            string_view left = w.substr(0, i); // O(1)
            string_view right = w.substr(i);

            if (!dict.count(left)) continue; // O(L) — hashing takes time proportional to its length

            if (dict.count(right) || canform(right))
                return memo[w] = true;
        }

        return memo[w] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        // string_view into words[i] — safe since `words` stays alive throughout
        for (auto& w : words) dict.insert(w);  

        for (string& w : words) {
            if (canform(w))
                res.push_back(w);
        }

        return res;
    }
};

// Optimal using index


// T: O(N * L^3) where N = number of words, L = max word length
// substr is O(L), and we try O(L) split points per word, memoized
// S: O(N * L) for memo + dict storage
class Solution {
public:
    unordered_set<string> dict;
    unordered_map<string, bool> memo;

    bool canform(string& w) {
        if (memo.count(w)) return memo[w];

        int n = w.size();

        for (int i = 1; i < n; i++) {
            string left = w.substr(0, i);
            string right = w.substr(i, n);

            if (!dict.count(left)) continue;

            if (dict.count(right) || canform(right))
                return memo[w] = true;
        }

        return memo[w] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        dict.insert(words.begin(), words.end());

        for (string& w : words) {
            dict.erase(w);
            if (canform(w))
                res.push_back(w);

            dict.insert(w);
        }
        
        return res;
    }
};

// for each word, check each split
// if prefix and suffix in dict, true