// T: O((wordlen * (n/wordlen)) * wordlen) -> O(n * wordlen)
// S: O(m * wordlen)

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int wordlen = words[0].size();
        int m = words.size();
        vector<int> res = {};
        
        // word: freq
        unordered_map<string, int> req;
        for (string w: words) 
            req[w]++;

        for (int offset = 0; offset < wordlen; offset++) {
            unordered_map<string, int> mp;
            int l = offset;
            int r = offset;
            int matched = 0;

            while (r + wordlen <= n) {
                // use string view : string_view curr(s.data() + r, wordlen) -> faster O(1)
                string curr = s.substr(r, wordlen); // O(wordlen)
                r += wordlen;

                if (req.count(curr)) {
                    mp[curr]++;
                    matched++;
                    
                    while (mp[curr] > req[curr]) {
                        string lword = s.substr(l, wordlen);
                        mp[lword]--;
                        matched--;
                        l += wordlen;
                    }      

                    if (matched == m) {
                        res.push_back(l);
                        string lword = s.substr(l, wordlen);
                        mp[lword]--;
                        matched--;
                        l += wordlen;
                        continue;
                    }

                } else {
                    // invalid word
                    l = r;
                    matched = 0;
                    mp.clear();
                }
            }
        }
        return res;
    }   
};

// need to try all offsets, eg:
// s    = "foobarefoobar"
// words = ["foo", "bar"]
// ans = [0, 7], answers in diff offsets