// T: O(n) (at most 2 dots per char, so max is O(26^2 * n))
// S: O(t+n)
// n -> length of string
// t -> total number of nodes

class TrieNode {
public:
    vector<TrieNode*> children;
    bool word;

    TrieNode() : children(26, nullptr), word(false) {}
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c: word) {
            if (curr->children[c-'a'] == nullptr) {
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->word = true;
    }

    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* curr = root;

        for (int i = j; i < word.size(); i++) {
            char c = word[i];
            if (c != '.') {
                if (curr->children[c - 'a'] == nullptr) {
                    return false;
                }
                curr = curr->children[c - 'a'];
            } else {
                for (TrieNode* child : curr->children) {
                    if (child != nullptr && dfs(word, i+1, child))
                        return true;
                }
                return false;
            }
        }
        return curr->word;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
