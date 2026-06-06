// T: O(KL + MN*3^L)
// S: O(KL + L)
// Board: M*N
// L: max length of a word
// K: size of words list

class Trie {
public:
    struct Node {
        unordered_map<char, Node*> children;
        bool end = false;
        int idx = -1;
    }; 

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string& word, int i) {
        Node* curr = root;
        for (char c: word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new Node();
            }
            curr = curr->children[c];
        }
        curr->end = true;
        curr->idx = i;
    }
};

class Solution {
public:
    vector<string> res = {};

    void dfs(int r, int c, Trie::Node* trienode, vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        char ch = board[r][c];
        if (ch == '#') return;

        if (!trienode->children.count(ch)) {
            return;
        }

        trienode = trienode->children[ch];

        if (trienode->end) {
            res.push_back(words[trienode->idx]);
            // mark as pushed
            trienode->end = false;
        } 

        board[r][c] = '#';
        // expand 4 directions
        if (r+1 < m) {
            dfs(r+1, c, trienode, board, words);
        }
        if (c+1 < n) {
            dfs(r, c+1, trienode, board, words);
        }
        if (r-1 >= 0) {
            dfs(r-1, c, trienode, board, words);
        }
        if (c-1 >= 0) {
            dfs(r, c-1, trienode, board, words);
        }

        board[r][c] = ch;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int l = words.size();
        Trie* trie = new Trie();
        for (int i = 0; i < l; i++) {
            trie->insert(words[i], i);
        }

        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, trie->root, board, words);
            }
        }

        return res;

    }
};



// TLE | Trie + Backtracking

// T: O(KL + MN*L*3^L)
// S: O(KL + L^2)

class Trie {
public:
    struct Node {
        unordered_map<char, Node*> children;
        bool end = false;
        int idx = -1;
    }; 

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string& word, int i) {
        Node* curr = root;
        for (char c: word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new Node();
            }
            curr = curr->children[c];
        }
        curr->end = true;
        curr->idx = i;
    }

    pair<bool, int> search(string& word) {
        Node* curr = root;
        for (char c: word) {
            if (curr->children.find(c) == curr->children.end()) {
                return {false, -1};
            } else {
                curr = curr->children[c];
            }
        }
        if (curr->end) return {true, curr->idx};
        return {false, -1};
    }

    bool startsWith(string& prefix) {
        Node* curr = root;
        for (char c: prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            } else {
                curr = curr->children[c];
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<string> res = {};
    unordered_set<string> pushed;

    void dfs(int r, int c, string curr, vector<vector<char>>& board, Trie* trie, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        char ch = board[r][c];
        if (ch == '#') return;

        curr += ch;
        if (!trie->startsWith(curr)) {
            return;
        }

        pair<bool, int> searchres = trie->search(curr);
        if (searchres.first && !pushed.count(curr)) {
            res.push_back(words[searchres.second]);
            pushed.insert(curr);
        } 

        board[r][c] = '#';
        // expand 4 directions
        if (r+1 < m) {
            dfs(r+1, c, curr, board, trie, words);
        }
        if (c+1 < n) {
            dfs(r, c+1, curr, board, trie, words);
        }
        if (r-1 >= 0) {
            dfs(r-1, c, curr, board, trie, words);
        }
        if (c-1 >= 0) {
            dfs(r, c-1, curr, board, trie, words);
        }

        board[r][c] = ch;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int k = words.size();
        Trie* root = new Trie();
        // O(KL) Time and Space where L is max length
        for (int i = 0; i < k; i++) {
            root->insert(words[i], i);
        }

        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Max depth is L
                // O(3^L)
                // O(MN*)
                dfs(i, j, "", board, root, words);
            }
        }

        return res;

    }
};
