// 133. Clone Graph
// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* dfs(Node* node, unordered_map<Node*, Node*>& map) {
        if (node == nullptr) return nullptr;

        if (map.count(node)) {
            return map[node];
        }

        Node* newNode = new Node(node->val);
        map[node] = newNode;
        for (Node* neighbor: node->neighbors) {
            map[node]->neighbors.push_back(dfs(neighbor, map));
        }

        return newNode;
    }


    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldToNew;
        return dfs(node, oldToNew);
    }
};