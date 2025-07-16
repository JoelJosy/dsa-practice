// 
// https://leetcode.com/problems/copy-list-with-random-pointer/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node* curr = head;

        // First pass: Create all nodes without setting pointers
        while (curr != nullptr) {
            map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Second pass: Set next and random pointers
        curr = head;
        while (curr != nullptr) {
            map[curr]->next = map[curr->next];     // Handles nullptr automatically
            map[curr]->random = map[curr->random]; // Handles nullptr automatically
            curr = curr->next;
        }

        return map[head];
    }
};