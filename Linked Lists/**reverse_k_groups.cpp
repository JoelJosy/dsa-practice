// 25 Reverse Nodes in K-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy; // node before curr group
        
        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) break;

            ListNode* groupNext = kth->next; // node after curr group
            
            ListNode* prev = groupNext; // first node of group connects to kth + 1 node
            ListNode* curr = groupPrev->next;
            while (curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            ListNode* oldGroupHead = groupPrev->next; // get the new tail / old head
            groupPrev->next = kth; // connect group prev to new head
            groupPrev = oldGroupHead;
        }

        return dummy->next;

    }

    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};