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

// Using vector (slightly faster but more constant space)

struct TrieNode {
    TrieNode*  children(26, nullptr);
    bool end = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root= new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur=root;
        for(char c:word){
            int val=c-'a';
            if(cur->children[val]==nullptr){
                cur->children[val]=new TrieNode();
            }
            cur=cur->children[val];

        }
        cur->end=true;
        
    }
    
    bool search(string word) {
        TrieNode* cur=root;
        for(char c:word){
             int val=c-'a';
             if(cur->children[val]==nullptr){
                return false;
             }
             cur=cur->children[val];
        }
            return cur->end;

    }
    
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(char c:prefix){
             int val=c-'a';
             if(cur->children[val]==nullptr){
                return false;
             }
             cur=cur->children[val];
    }
    return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */