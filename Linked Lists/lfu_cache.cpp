class LFUCache {
public:
    LFUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node* node = keyNode[key];

        // remove from old dll
        auto oldpos= node->it;
        freqList[node->cnt].erase(oldpos);

        // update minfreq if needed
        if (node->cnt == minfreq &&
            freqList[minfreq].empty())
            minfreq++;

        // add to new dll
        node->cnt++;
        freqList[node->cnt].push_front(node);
        node->it = freqList[node->cnt].begin();

        return node->val;
    }
    
    void put(int key, int value) {
        if (cap == 0)
            return;

        // existing key
        if (keyNode.find(key) != keyNode.end()) {
            keyNode[key]->val = value;
            get(key);
            return;
        }

        // evict LFU
        if (keyNode.size() == cap) {
            Node* lfuNode = freqList[minfreq].back();
            freqList[minfreq].pop_back();
        
            // erase from keynode map
            keyNode.erase(lfuNode->key);
            delete lfuNode;
        }

        // insert new key
        Node* node = new Node;
        node->key = key;
        node->val = value;
        node->cnt = 1;
        freqList[1].push_front(node);
        node->it = freqList[1].begin();
        
        // update minFreq
        minfreq = 1;
        keyNode[key] = node;
    }

private:
    int cap;
    struct Node {
        int key;
        int val;
        int cnt;
        list<Node*>::iterator it;
    };
    
    int minfreq = 0;
    // freq -> LRU
    unordered_map<int, list<Node*>> freqList;
    // key -> Node
    unordered_map<int, Node*> keyNode;
};

// frequency wise LRU
// map freq -> DLL
// track min freq
// map key -> val, freq, iterator to list


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */