// T: O(N*M + N*M^2*26) => O(N*M^2)
// S: O(N*M)
// N -> wordList length
// M -> word length

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int m = beginWord.size();
        // hashing each costs O(M)
        unordered_set<string> wordset;
        for (string w: wordList) wordset.insert(w);

        if (!wordset.count(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                string curr = q.front();
                q.pop();
                if (curr == endWord) return level;

                for (int i = 0; i < m; i++) {
                    char original = curr[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        curr[i] = c;
                        if (wordset.count(curr)) {
                            q.push(curr);
                            // add to visited
                            wordset.erase(curr);
                        }
                    }
                    curr[i] = original;
                }
            }
            level++;  
        }
        return 0;
    }
};

// BFS 
// Nodes are words, edges if differ by 1 letter
// replace each char with a-z and check if in list
// do BFS tracking level
// return level when reached