// Time:
// * insert(word) → O(L)
// * search(word) → O(L)
// * startsWith(prefix) → O(L)
// where L is the length of the word/prefix.

// Space: O(total characters inserted) nodes in the trie.

class PrefixTree {
public:
    struct Node {
        unordered_map<char, Node*> children;
        bool end = false;
    };
    
    Node* root;

    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for (char c: word) {
            if (curr->children.find(c) != curr->children.end()) {
                curr = curr->children[c];
            } else {
                curr->children[c] = new Node();
                curr = curr->children[c];
            }
        }
        curr->end = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (char c: word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            } else {
                curr = curr->children[c];
            }
        }
        if (curr->end) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
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
