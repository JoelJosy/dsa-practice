// T: O(n)
// S: O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* level = root;
        while (level->left) {           // while there is another level
            Node* curr = level;

            while (curr) {
                // Same parent
                curr->left->next = curr->right;

                // Across parents
                if (curr->next)
                    curr->right->next = curr->next->left;

                curr = curr->next;
            }

            level = level->left;
        }

        return root;
    }
};

// T: O(n)
// S: O(n)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                Node* node = q.front(); q.pop();

                if (i == len - 1) node->next = NULL;
                else {
                    node->next = q.front();
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }
};