// BFS 
// Nodes are words, edges if differ by 1 letter
// replace each char with a-z and check if in list
// do BFS tracking level
// return level when reached

// Time: O(N*M + N*M^2*26) => O(N*M^2)
// Space: O(N*M)
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


// Using Wildcard Patterns
// Same overall Time, but much fewer constant lookups
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord)) return 0;

        unordered_map<string, vector<string>> patternMap;

        // Step 1: Build pattern map
        for (string word : wordSet) {
            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                pattern[i] = '*';
                patternMap[pattern].push_back(word);
            }
        }

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        int level = 1;

        // Step 2: BFS
        while (!q.empty()) {
            int sz = q.size();

            for (int k = 0; k < sz; k++) {
                string word = q.front();
                q.pop();

                if (word == endWord) return level;

                for (int i = 0; i < word.size(); i++) {
                    string pattern = word;
                    pattern[i] = '*';

                    for (string nei : patternMap[pattern]) {
                        if (!visited.count(nei)) {
                            visited.insert(nei);
                            q.push(nei);
                        }
                    }
                }
            }

            level++;
        }

        return 0;
    }
};
